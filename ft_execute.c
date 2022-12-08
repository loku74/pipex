/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:21:50 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/08 11:16:01 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	is_in(char *str, char *charset)
{
	int	i;
	int	k;

	i = 0;
	while (str[i])
	{
		k = 0;
		while (charset[k])
		{
			if (str[i] == charset[k])
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

static void	ft_execute_infile(t_pipex *pipex, char **argv, int i, int argc)
{
	int		k;
	char	**cmd_args;
	char	*cmd;

	dup2(pipex->fd_in, STDIN_FILENO);
	dup2(pipex->pipes[0][1], STDOUT_FILENO);
	ft_close_pipes(pipex->pipes, argc - 4);
	close(pipex->fd_in);
	close(pipex->fd_out);
	k = 0;
	while (pipex->paths[k])
	{
		if (is_in(argv[i + 2], "\"\'{}") == 1)
			cmd_args = ft_pipex_split(argv[i + 2]);
		else
			cmd_args = ft_split(argv[i + 2], ' ');
		cmd = ft_strjoin(pipex->paths[k], cmd_args[0]);
		execve(cmd, cmd_args, NULL);
		free(cmd);
		ft_free_cmds(cmd_args);
		k++;
	}
	ft_putstr_fd("Command not found: ", STDERR_FILENO);
	ft_putendl_fd(argv[i + 2], STDERR_FILENO);
	exit(0);
}

static void	ft_execute_outfile(t_pipex *pipex, char **argv, int i, int argc)
{
	int		k;
	char	**cmd_args;
	char	*cmd;

	dup2(pipex->pipes[i - 1][0], STDIN_FILENO);
	dup2(pipex->fd_out, STDOUT_FILENO);
	ft_close_pipes(pipex->pipes, argc - 4);
	close(pipex->fd_in);
	close(pipex->fd_out);
	k = 0;
	while (pipex->paths[k])
	{
		if (is_in(argv[i + 2], "\"\'{}") == 1)
			cmd_args = ft_pipex_split(argv[i + 2]);
		else
			cmd_args = ft_split(argv[i + 2], ' ');
		cmd = ft_strjoin(pipex->paths[k], cmd_args[0]);
		execve(cmd, cmd_args, NULL);
		free(cmd);
		ft_free_cmds(cmd_args);
		k++;
	}
	ft_putstr_fd("Command not found: ", STDERR_FILENO);
	ft_putendl_fd(argv[i + 2], STDERR_FILENO);
	exit(0);
}

static void	ft_execute_pipe(t_pipex *pipex, char **argv, int i, int argc)
{
	int		k;
	char	**cmd_args;
	char	*cmd;

	dup2(pipex->pipes[i - 1][0], STDIN_FILENO);
	dup2(pipex->pipes[i][1], STDOUT_FILENO);
	ft_close_pipes(pipex->pipes, argc - 4);
	close(pipex->fd_in);
	close(pipex->fd_out);
	k = 0;
	while (pipex->paths[k])
	{
		if (is_in(argv[i + 2], "\"\'{}") == 1)
			cmd_args = ft_pipex_split(argv[i + 2]);
		else
			cmd_args = ft_split(argv[i + 2], ' ');
		cmd = ft_strjoin(pipex->paths[k], cmd_args[0]);
		execve(cmd, cmd_args, NULL);
		free(cmd);
		ft_free_cmds(cmd_args);
		k++;
	}
	ft_putstr_fd("Command not found: ", STDERR_FILENO);
	ft_putendl_fd(argv[i + 2], STDERR_FILENO);
	exit(0);
}

void	ft_execute_command(t_pipex *pipex, char **argv, int i, int argc)
{
	if (i == 0)
		ft_execute_infile(pipex, argv, i, argc);
	if (i == argc - 4)
		ft_execute_outfile(pipex, argv, i, argc);
	else
		ft_execute_pipe(pipex, argv, i, argc);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:21:50 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/07 18:21:24 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		cmd_args = ft_split(argv[i + 2], ' ');
		cmd = ft_strjoin(pipex->paths[k], cmd_args[0]);
		execve(cmd, cmd_args, NULL);
		free(cmd);
		ft_free_cmds(cmd_args);
		k++;
	}
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	ft_putstr_fd("Command not found: ", STDERR_FILENO);
	ft_putstr_fd(argv[i + 2], STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(errno);
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
		cmd_args = ft_split(argv[i + 2], ' ');
		cmd = ft_strjoin(pipex->paths[k], cmd_args[0]);
		execve(cmd, cmd_args, NULL);
		free(cmd);
		ft_free_cmds(cmd_args);
		k++;
	}
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	ft_putstr_fd("Command not found: ", STDERR_FILENO);
	ft_putstr_fd(argv[i + 2], STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(errno);
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
		cmd_args = ft_split(argv[i + 2], ' ');
		cmd = ft_strjoin(pipex->paths[k], cmd_args[0]);
		execve(cmd, cmd_args, NULL);
		free(cmd);
		ft_free_cmds(cmd_args);
		k++;
	}
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	ft_putstr_fd("Command not found: ", STDERR_FILENO);
	ft_putstr_fd(argv[i + 2], STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(errno);
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

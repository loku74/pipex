/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:12:55 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/08 15:54:15 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_create_paths(t_pipex *pipex, char **envp)
{
	int		i;
	char	**paths;
	char	*temp;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])) != NULL)
			paths = ft_split(envp[i] + ft_strlen("PATH="), ':');
		i++;
	}
	i = 0;
	while (paths[i])
	{
		temp = paths[i];
		paths[i] = ft_strjoin(temp, "/");
		free(temp);
		i++;
	}
	pipex->paths = paths;
}

void	ft_create_pipes(t_pipex *pipex, int argc)
{
	int	**pipes;
	int	i;

	pipes = (int **)malloc(sizeof(int *) * argc - 4);
	if (pipes == NULL)
		ft_exit_1(pipex, errno);
	i = 0;
	while (i < argc - 4)
	{
		pipes[i] = (int *)malloc(sizeof(int) * 2);
		if (pipes[i] == NULL)
			ft_exit_2(pipex, pipes, i, errno);
		pipe(pipes[i]);
		i++;
	}
	pipex->pipes = pipes;
}

void	ft_create_forks(t_pipex *pipex, int argc, char **argv)
{
	int	*pids;
	int	i;

	pids = (int *)malloc(sizeof(int) * (argc - 3));
	if (pids == NULL)
		ft_exit_3(pipex, argc, errno);
	i = 0;
	while (i < argc - 3)
	{
		pids[i] = fork();
		if (pids[i] == 0)
			ft_execute_command(pipex, argv, i, argc);
		i++;
	}
	pipex->pids = pids;
}

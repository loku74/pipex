/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:26:57 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/05 19:06:36 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **envp)
{
	char **tab;

	tab = NULL;
	for (int i = 0; envp[i]; i++)
	{
		if (ft_strnstr(envp[i], "PATH", ft_strlen(envp[i])))
			tab = ft_split(ft_strnstr(envp[i], "/", ft_strlen(envp[i])), ':');
	}
	return (tab);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];

	int	pid, pid2;
	int	fd_in;
	int	fd_out;
	int	fd_ex;
	char **tab;
	char **path;
	char *str;

	path = find_path(envp);

	pipe(fd);
	fd_in = open(argv[1], O_RDONLY);
	fd_out = open(argv[4], O_CREAT, O_TRUNC | O_RDWR);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd_in, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		
			tab = ft_split(argv[2], ' ');
			for (int k = 0; path[k]; k++)
			{
				str = ft_strjoin(path[k], tab[0]);
				execve(str, tab, envp);
				free(str);
			}
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		tab = ft_split(argv[3], ' ');
			for (int k = 0; path[k]; k++)
			{
				str = ft_strjoin(path[k], tab[0]);
				execve(str, tab, envp);
				free(str);
			}
	}
	return (0);
}
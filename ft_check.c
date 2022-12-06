/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:21:38 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/06 17:23:01 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**ft_get_path(char **envp)
{
	char	**path;
	int		i;

	path = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", ft_strlen(envp[i])))
			path = ft_split(ft_strnstr(envp[i], "/", ft_strlen(envp[i])), ':');
		i++;
	}
	return (path);
}

static int	ft_display_error(int errnum, void *content)
{
	ft_printf("%s: %s\n", strerror(errnum), (char *)content);
	exit(errnum);
}

void	ft_check_input_error(t_pipex *pipex, int argc, char **argv, char **envp)
{
	int		i;
	int		k;
	char	*cmd;
	char	*cmd_path;

	i = 2;
	pipex->fd_in = open(argv[1], O_RDONLY);
	if (pipex->fd_in == -1)
		ft_display_error(errno, argv[1]);
	pipex->fd_out = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (pipex->fd_out == -1)
		ft_display_error(errno, argv[argc - 1]);
	pipex->paths = ft_get_path(envp);
	while (i < argc - 1)
	{
		k = 0;
		cmd = ft_strjoin("/", argv[i]);
		while (pipex->paths[k])
		{
			cmd_path = ft_strjoin(pipex->paths[k], cmd);
			if (access(cmd_path, X_OK) != -1)
				break;
			free(cmd_path);
			k++;
		}
		if (pipex->paths[k] == NULL)
		{
			ft_printf("Command not found: %s\n", argv[i]);
		}
		else if (errno != EEXIST && pipex->paths[k] == NULL)
			ft_display_error(errno, argv[i]);
		free(cmd);
		i++;
	}
}

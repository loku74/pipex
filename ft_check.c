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

// static char	**ft_get_path(char **envp)
// {
// 	char	**path;
// 	int		i;

// 	path = NULL;
// 	i = 0;
// 	while (envp[i])
// 	{
// 		if (ft_strnstr(envp[i], "PATH", ft_strlen(envp[i])))
// 			path = ft_split(ft_strnstr(envp[i], "/", ft_strlen(envp[i])), ':');
// 		i++;
// 	}
// 	return (path);
// }

static void	ft_display_error(int errnum, void *content)
{
	ft_printf("%s: %s\n", strerror(errnum), (char *)content);
}

int	ft_check_files_error(t_pipex *pipex, int argc, char **argv)
{
	pipex->fd_in = open(argv[1], O_RDONLY);
	if (pipex->fd_in == -1)
	{
		ft_display_error(errno, argv[1]);
		return (1);
	}
	pipex->fd_out = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (pipex->fd_out == -1)
	{
		ft_display_error(errno, argv[argc - 1]);
		return (1);
	}
	return (0);
}

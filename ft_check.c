/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:21:38 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/07 17:50:55 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_display_error(int errnum, char *content)
{
	ft_putstr_fd(strerror(errnum), STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(content, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(errnum);
}

int	ft_check_files_error(t_pipex *pipex, int argc, char **argv)
{
	pipex->fd_in = open(argv[1], O_RDONLY);
	if (pipex->fd_in == -1)
	{
		ft_display_error(errno, argv[1]);
		return (1);
	}
	pipex->fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd_out == -1)
	{
		ft_display_error(errno, argv[argc - 1]);
		return (1);
	}
	return (0);
}

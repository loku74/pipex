/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:34:45 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/08 15:54:19 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_exit_1(t_pipex *pipex, int err)
{
	ft_free_paths(pipex->paths);
	ft_putstr_fd(strerror(err), 2);
	exit(err);
}

void	ft_exit_2(t_pipex *pipex, int **pipes, int n, int err)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
	ft_exit_1(pipex, err);
}

void	ft_exit_3(t_pipex *pipex, int argc, int err)
{
	ft_exit_2(pipex, pipex->pipes, argc - 4, err);
}

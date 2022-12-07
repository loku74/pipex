/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:38:34 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/07 17:45:07 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_pipes(int **pipes, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 4)
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
}

void	ft_free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths[i]);
	free(paths);
}

void	ft_free_cmds(char **cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
	{
		free(cmds[i]);
		i++;
	}
	free(cmds[i]);
	free(cmds);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 10:04:49 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/04 13:48:34 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_create_forks(int **pids, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (*pids)
		{
			(*pids)[i] = fork();
			if ((*pids)[i] == 0)
				return ;
			else if ((*pids)[i] == -1)
			{
				free(*pids);
				return ;
			}
		}
		i++;
	}
}

int	*ft_create_pids(int argc)
{
	int	*pids;

	pids = (int *)malloc(sizeof(int) * (argc - 2));
	if (pids == NULL)
		return (NULL);
	return (pids);
}

int	**ft_create_pipes(int argc)
{
	int	**pipes;
	int	i;

	pipes = (int **)malloc(sizeof(int *) * (argc - 1));
	if (pipes == NULL)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		pipes[i] = (int *)malloc(sizeof(int) * 2);
		if (pipes[i] == NULL || pipe(pipes[i]) == -1)
		{
			ft_free_pipes(pipes, i);
			return (NULL);
		}
		i++;
	}
	return (pipes);
}

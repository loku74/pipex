/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:22:50 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/04 18:05:00 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	pipex(int **pipes, int *pids, int argc, char **argv)
{
	int		i;

	ft_create_forks(&pids, argc - 2);
	if (pids)
	{
		i = 0;
		while (i < argc - 2)
		{
			if (pids[i] == 0)
			{
				ft_execute_command(pipes, i, argc - 1, argv);
				ft_close_all_pipes(pipes, argc - 1);
				ft_free_all(pipes, pids, argc - 1);
				exit(0);
			}
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int		**pipes;
	int		*pids;

	if (argc < 5)
		return (0);
	pipes = ft_create_pipes(argc);
	if (pipes == NULL)
		return (0);
	pids = ft_create_pids(argc);
	if (pids == NULL)
		return (0);
	pipex(pipes, pids, argc, argv);

	char content[100];
	read(pipes[0][0], content, 100);
	ft_printf("%s\n",content);
	ft_close_all_pipes(pipes, argc - 1);
	ft_free_all(pipes, pids, argc - 1);
	return (0);
}

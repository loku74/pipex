/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:08:34 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/08 10:47:55 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		i;

	if (argc >= 5 && ft_check_files_error(&pipex, argc, argv) != 1)
	{
		ft_create_paths(&pipex, envp);
		ft_create_pipes(&pipex, argc);
		ft_create_forks(&pipex, argc, argv);
		ft_close_pipes(pipex.pipes, argc - 4);
		close(pipex.fd_out);
		close(pipex.fd_in);
		i = 0;
		while (i < argc - 3)
		{
			waitpid(pipex.pids[i], NULL, 0);
			i++;
		}
		ft_free_paths(pipex.paths);
		ft_free_pipes(pipex.pipes, argc);
		free(pipex.pids);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:22:14 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/07 17:46:32 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/includes/libft.h"
# include <fcntl.h>
# include <string.h>
# include <errno.h>

typedef struct s_pipex
{
	int		fd_in;
	int		fd_out;
	int		*pids;
	int		**pipes;
	char	**paths;
}	t_pipex;

// ft_close.c
void	ft_close_pipes(int **pipes, int n);

// ft_check.c
int		ft_check_files_error(t_pipex *pipex, int argc, char **argv);

// ft_create.c
void	ft_create_paths(t_pipex *pipex, char **envp);
void	ft_create_pipes(t_pipex *pipex, int argc);
void	ft_create_forks(t_pipex *pipex, int argc, char **argv);

// ft_execute.c
void	ft_execute_command(t_pipex *pipex, char **argv, int i, int argc);

// ft_exit.c
void	ft_exit_1(t_pipex *pipex, int err);
void	ft_exit_2(t_pipex *pipex, int **pipes, int argc, int err);
void	ft_exit_3(t_pipex *pipex, int argc, int err);

// ft_free.c
void	ft_free_paths(char **paths);
void	ft_free_cmds(char **cmds);
void	ft_free_pipes(int **pipes, int argc);

#endif
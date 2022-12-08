/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:22:14 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/08 16:38:16 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/includes/libft.h"
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
	char	**envp;
}	t_pipex;

// ft_close_bonus.c
void	ft_close_pipes(int **pipes, int n);

// ft_check_bonus.c
int		ft_check_files_error(t_pipex *pipex, int argc, char **argv);

// ft_create_bonus.c
void	ft_create_paths(t_pipex *pipex, char **envp);
void	ft_create_pipes(t_pipex *pipex, int argc);
void	ft_create_forks(t_pipex *pipex, int argc, char **argv);

// ft_execute_bonus.c
void	ft_execute_command(t_pipex *pipex, char **argv, int i, int argc);

// ft_exit_bonus.c
void	ft_exit_1(t_pipex *pipex, int err);
void	ft_exit_2(t_pipex *pipex, int **pipes, int argc, int err);
void	ft_exit_3(t_pipex *pipex, int argc, int err);

// ft_free_bonus.c
void	ft_free_paths(char **paths);
void	ft_free_cmds(char **cmds);
void	ft_free_pipes(int **pipes, int argc);

// ft_utils_bonus.c && ft_utils2_bonus.c
char	**ft_pipex_split(char *str);
int		is_in(char *str, char *charset);
char	*ft_pipex_strrchr(char *s, int c);

#endif
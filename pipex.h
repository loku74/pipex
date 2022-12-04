/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:22:14 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/04 17:24:19 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/includes/libft.h"
# include <fcntl.h>

char	*ft_get_input(char *filename);

int		*ft_create_pids(int argc);

int		**ft_create_pipes(int argc);

size_t	ft_get_file_length(char *filename);
size_t	ft_get_size(int fd);

void	ft_close_all_pipes(int **pipes, int count);
void	ft_create_forks(int **pids, int count);
void	ft_execute_command(int **pipes, int index, int argc, char **argv);
void	ft_free_all(int **pipes, int *pids, int count);
void	ft_free_pipes(int **pipes, int count);

#endif
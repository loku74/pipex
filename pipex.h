/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:22:14 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/06 17:23:01 by lbourniq         ###   ########.fr       */
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

void	ft_check_input_error(t_pipex *pipex, int argc, char **argv, char **envp);

#endif
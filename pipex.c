/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:08:34 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/06 16:57:17 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	(void)envp;
	if (argc >= 5)
	{
		ft_printf("%d\n", ft_check_files_error(&pipex, argc, argv));
	}
	return (0);
}

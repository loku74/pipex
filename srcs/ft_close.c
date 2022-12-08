/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:31:38 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/08 15:53:34 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_close_pipes(int **pipes, int n)
{
	int	k;

	k = 0;
	while (k < n)
	{
		close(pipes[k][0]);
		close(pipes[k][1]);
		k++;
	}	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:44:48 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/03 17:09:31 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	get_file_length(char *filename)
{
	size_t	i;
	int		fd;
	char	c;

	fd = open(filename, O_RDONLY);
	i = 0;
	while (read(fd, &c, 1) == 1)
		i++;
	close(fd);
	return (i);
}

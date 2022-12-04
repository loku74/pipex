/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:44:48 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/04 13:51:27 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_input(char *filename)
{
	char	*res;
	int		fd;

	res = (char *)malloc(sizeof(char) * ft_get_file_length(filename));
	if (res == NULL)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	read(fd, res, ft_get_file_length(filename));
	return (res);
}

size_t	ft_get_size(int fd)
{
	size_t	i;
	int		temp_fd;
	char	c;

	temp_fd = dup(fd);
	i = 0;
	while (read(temp_fd, &c, 1) == 1)
		i++;
	return (i);
}

size_t	ft_get_file_length(char *filename)
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

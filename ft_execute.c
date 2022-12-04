/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:43:49 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/04 18:05:00 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	format_tab(char **tab, char *content)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	tab[i] = content;
}

static int	ft_write_input(int **pipes, int i, char **argv)
{
	int		b_read;
	int		pid;
	char	*content;
	char	**tab;

	content = (char *)malloc(sizeof(char) * ft_get_file_length(argv[1]));
	if (content == NULL)
		return (0);
	b_read = write(open(argv[1], O_RDONLY), content, ft_get_file_length(argv[1]));
	tab = ft_split(argv[i + 2], ' ');
	format_tab(tab, content);
	dup2(pipes[i][1], STDOUT_FILENO);
	pid = fork();
	if (pid == 0)
	{
		execve("grep M", tab, NULL);
	}
	free(tab);
	return (b_read);
}

void	ft_execute_command(int **pipes, int i, int argc, char **argv)
{
	int	b_read;
	(void)argc;

	b_read = 0;
	if (i == 0)
		b_read = ft_write_input(pipes, i, argv);
}

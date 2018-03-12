/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 15:44:28 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/21 15:44:29 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	put_in_map(char **parts, t_event *event, int a)
{
	int		i;

	i = -1;
	while (parts[++i])
		event->world_map[a][i] = atoi(parts[i]);
}

void	read_from_file(t_event *event)
{
	char	*line;
	int		fd;
	int		a;

	a = 0;
	if ((fd = open(FILE_NAME, O_RDONLY)) < 0)
		exit_on_error("FILE_NAME macro incorrect");
	while (get_next_line(fd, &line))
	{
		put_in_map(ft_strsplit(line, ' '), event, a);
		free(line);
		a++;
	}
}

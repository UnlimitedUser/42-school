/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:06:57 by dsclearo          #+#    #+#             */
/*   Updated: 2016/12/06 15:47:06 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	*put_in_struct(char **tockens, int row, int line, int *width)
{
	t_point	*points;
	int		i;
	int		size;

	i = -1;
	size = 0;
	while (tockens[size])
		size++;
	*width = size;
	if (!(points = ft_memalloc(sizeof(t_point) * size)))
		return (NULL);
	while (tockens[++i])
	{
		points[i].z = ft_atoi(tockens[i]);
		points[i].x = line;
		points[i].y = row * 10;
		points[i].color = pick_color(points[i].z);
		points[i].offx = 0;
		points[i].offy = 0;
		line += 10;
	}
	return (points);
}

static int		add_elem(t_line **line)
{
	t_line	*elem;

	if (!(elem = ft_memalloc(sizeof(*elem))))
		return (0);
	(*line)->next_line = elem;
	(*line) = elem;
	return (1);
}

int				init(t_line **t, int *f, char *file)
{
	if (((*f = open(file, O_RDONLY)) == -1))
		return (0);
	if (!(*t = ft_memalloc(sizeof(t_line))))
		return (0);
	return (1);
}

int				read_from_file(char *file, t_line **oneline, int *w,
		int *rows)
{
	char	*line;
	int		f;
	int		row;
	t_line	*t;
	t_line	*prev;

	row = 0;
	if (!init(&t, &f, file))
		return (0);
	*oneline = t;
	while (get_next_line(f, &line))
	{
		if (!(t->points = put_in_struct(ft_strsplit(line, ' '), row, 0, w)))
			return (0);
		t->length = *w;
		prev = t;
		if (!(add_elem(&t)))
			return (0);
		ft_memdel((void **)&line);
		row++;
	}
	prev->next_line = NULL;
	ft_memdel((void **)&t);
	*rows = row;
	return (1);
}

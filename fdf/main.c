/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:07:23 by dsclearo          #+#    #+#             */
/*   Updated: 2016/12/05 19:26:58 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_int_vals(t_event *event, int width, int rows)
{
	event->lines = rows;
	increase_offset(event->line, width * 10, rows * 10);
	event->mlx = mlx_init();
	event->window = mlx_new_window(event->mlx, width * 30, rows * 30, "Fdf");
	redraw(event);
	get_center(event);
}

int		main(int ac, char **av)
{
	t_event	event;
	int		width;
	int		rows;

	if (ac != 2 && ac != 4)
	{
		ft_putstr("usage: ./fdf file_name, or ./fdf file_name width height\n");
		exit(0);
	}
	ft_putstr("Press h on keyboard for help\n");
	event.display_help = 0;
	if (!(read_from_file(av[1], &event.line, &width, &rows)))
	{
		ft_putstr("Could not read from file, or malloc error\n");
		exit(0);
	}
	if (ac == 4)
	{
		width = ft_atoi(av[2]);
		rows = ft_atoi(av[3]);
	}
	ft_int_vals(&event, width, rows);
	mlx_key_hook(event.window, handle_key, &event);
	mlx_expose_hook(event.window, redraw, &event);
	mlx_loop(event.mlx);
}

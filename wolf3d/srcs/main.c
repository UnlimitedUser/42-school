/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 22:16:14 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/20 22:16:14 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_mlx(t_event *event)
{
	event->mlx = mlx_init();
	event->win = mlx_new_window(event->mlx, WIN_WIDTH, WIN_HEIGHT, TITLE);
	event->image.image = mlx_new_image(event->mlx, WIN_WIDTH, WIN_HEIGHT);
	event->image.data_address = mlx_get_data_addr(event->image.image,
		&event->image.bits_per_pixel, &event->image.size_line,
			&event->image.endian);
	event->direction.x = -1;
	event->direction.y = 0;
	event->plane.x = 0;
	event->plane.y = 0.66;
	event->time = 0;
	event->old_time = 0;
	event->player.x = 3;
	event->player.y = 3;
	event->go_up = 0;
	event->go_down = 0;
	event->turn_right = 0;
	event->turn_left = 0;
	event->fast = 0;
	event->tex_num = 0;
}

int		main(int ac, char **av)
{
	t_event	event;

	(void)av;
	if (ac != 1)
		exit_on_error("Please run with no arguments");
	read_from_file(&event);
	print_r(&event);
	init_mlx(&event);
	generate_textures(&event);
	reload_image(&event);
	mlx_expose_hook(event.win, expose_hook, &event);
	mlx_hook(event.win, KEY_PRESS, KEY_PRESS_MASK, key_press, &event);
	mlx_hook(event.win, KEY_RELEASE, KEY_RELEASE_MASK, key_release, &event);
	mlx_loop_hook(event.mlx, loop_hook, &event);
	mlx_loop(event.mlx);
}

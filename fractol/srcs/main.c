/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 23:38:21 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/27 18:16:56 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	get_type(char *str, t_event *event)
{
	event->offset = 1000000;
	event->mouse.imag = 0;
	event->mouse.real = 0.279;
	event->zoom_offset.x = -0.5;
	event->zoom_offset.y = 0;
	event->scale = 0.65;
	event->mouse_motion = 1;
	if (ft_strequ(str, "mandelbrot"))
		event->type = mandelbrot;
	else if (ft_strequ(str, "julia"))
		event->type = julia;
	else if (ft_strequ(str, "imaginary"))
		event->type = imaginary;
	else if (ft_strequ(str, "julia2"))
		event->type = julia2;
	else if (ft_strequ(str, "julia3"))
		event->type = julia3;
	else if (ft_strequ(str, "julia4"))
		event->type = julia4;
	else if (ft_strequ(str, "b_ship"))
		event->type = b_ship;
	else if (ft_strequ(str, "dragon"))
		event->type = dragon;
	else if (ft_strequ(str, "serpinski"))
		event->type = serpinski;
}

void	get_function(t_event *event)
{
	if (event->type == mandelbrot)
		event->function = print_mandelbrot;
	else if (event->type == julia)
		event->function = print_julia;
	else if (event->type == imaginary)
		event->function = print_imaginary;
	else if (event->type == julia2)
		event->function = print_julia2;
	else if (event->type == julia3)
		event->function = print_julia3;
	else if (event->type == julia4)
		event->function = print_julia4;
	else if (event->type == b_ship)
		event->function = print_b_ship;
	else if (event->type == dragon)
		event->function = print_dragon;
	else if (event->type == serpinski)
		event->function = print_serpinski;
}

int		main(int ac, char **av)
{
	t_event		event;

	if (ac != 2 || (!ft_strequ(av[1], "mandelbrot") &&
				!ft_strequ(av[1], "julia") && !ft_strequ(av[1], "imaginary") &&
				!ft_strequ(av[1], "julia2") && !ft_strequ(av[1], "julia3") &&
				!ft_strequ(av[1], "julia4") && !ft_strequ(av[1], "b_ship") &&
				!ft_strequ(av[1], "dragon") && !ft_strequ(av[1], "serpinski")))
		show_usage_and_exit();
	event.mlx = mlx_init();
	event.window = mlx_new_window(event.mlx, WIN_WIDTH, WIN_HEIGHT, NAME);
	get_type(av[1], &event);
	get_function(&event);
	reload_image(&event, 1);
	mlx_mouse_hook(event.window, mouse_hook, &event);
	mlx_expose_hook(event.window, expose_hook, &event);
	mlx_hook(event.window, MOTION_NOTIFY, PTR_MOTION_MASK,
			mouse_motion, &event);
	mlx_key_hook(event.window, key_hook, &event);
	mlx_loop(event.mlx);
}

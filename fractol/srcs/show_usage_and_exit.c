/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_usage_and_exit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 23:57:25 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/20 13:14:35 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	show_usage_and_exit(void)
{
	ft_putendl("Usage: ./fractol mandelbrot, julia, "
			"imaginary, julia2, julia3, julia4, b_ship, "
			"dragon, serpinski");
	exit(0);
}

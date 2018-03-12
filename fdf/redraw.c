/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 18:53:22 by dsclearo          #+#    #+#             */
/*   Updated: 2016/12/05 19:09:14 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		redraw(t_event *env)
{
	mlx_clear_window(env->mlx, env->window);
	if (env->display_help)
		display_help(*env);
	from_2d_to_3d(env->line);
	put_points(env->line, env->mlx, env->window);
	return (1);
}

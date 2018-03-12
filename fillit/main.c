/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 16:28:37 by dsclearo          #+#    #+#             */
/*   Updated: 2016/11/21 14:51:46 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int			fd;
	t_vector	vectors[27][4];

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1 || (!(ft_populate(fd, &vectors))) || (close(fd) == -1))
			ft_putstr("error\n");
		else
			ft_print_map(ft_init_solve(vectors,
						ft_put_in_right_corner(&vectors)));
	}
	else
		ft_putstr("usage: ./fillit file_name\n");
}

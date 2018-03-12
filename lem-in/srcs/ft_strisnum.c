/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:22:18 by dsclearo          #+#    #+#             */
/*   Updated: 2017/01/12 11:22:20 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_strisnum(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		if (!ft_isdigit(s[i]))
			return (0);
	return (1);
}

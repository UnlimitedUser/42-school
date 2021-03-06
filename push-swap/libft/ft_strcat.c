/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 15:51:22 by dsclearo          #+#    #+#             */
/*   Updated: 2016/10/17 15:59:58 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	c;
	int	a;

	a = -1;
	c = -1;
	while (s1[++c])
		;
	while (s2[++a])
	{
		s1[c] = s2[a];
		c++;
	}
	s1[c] = s2[a];
	return (s1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 16:30:22 by dsclearo          #+#    #+#             */
/*   Updated: 2016/10/17 16:50:04 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cpy;

	i = 0;
	cpy = (unsigned char *)s;
	if (!s)
		cpy = (unsigned char *)0;
	if (n > 0)
		while (i < n)
		{
			if (cpy[i] == (unsigned char)c)
				return ((void*)&cpy[i]);
			i++;
		}
	return (NULL);
}

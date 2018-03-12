/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 16:10:04 by dsclearo          #+#    #+#             */
/*   Updated: 2016/10/10 16:43:58 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	d;
	unsigned char	*a;

	d = -1;
	a = (unsigned char *)b;
	while (++d < len)
		a[d] = (unsigned char)c;
	return ((void *)a);
}

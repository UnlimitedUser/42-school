/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 17:10:51 by dsclearo          #+#    #+#             */
/*   Updated: 2016/10/17 14:27:31 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void		*ret;

	if (!dst || !src)
		ret = (void *)0;
	ret = dst;
	if (dst < src)
		while ((size_t)(dst - ret) < len)
			*(unsigned char *)dst++ = *(unsigned char *)src++;
	else
		while (len-- > 0)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 16:54:51 by dsclearo          #+#    #+#             */
/*   Updated: 2016/10/20 16:02:18 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (!s)
		return (0);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (start--)
		s++;
	ft_strncpy(res, s, len);
	res[len] = '\0';
	return (res);
}

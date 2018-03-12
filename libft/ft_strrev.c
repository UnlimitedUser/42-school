/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 17:27:41 by dsclearo          #+#    #+#             */
/*   Updated: 2016/10/20 17:54:56 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*res;
	int		i;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * (i + 1));
	while (i--)
		*res++ = *(str + i);
	*res = '\0';
	return (res - ft_strlen(str));
}

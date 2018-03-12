/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 14:48:58 by dsclearo          #+#    #+#             */
/*   Updated: 2016/10/21 17:07:32 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtoupper(char *str)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof(str) * (ft_strlen(str) + 1));
	while (str[i])
	{
		res[i] = ft_toupper(str[i]);
		i++;
	}
	return (res);
}

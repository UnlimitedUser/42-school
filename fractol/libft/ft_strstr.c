/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:45:20 by dsclearo          #+#    #+#             */
/*   Updated: 2016/10/16 14:40:21 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	c;
	int	a;
	int	f;

	c = -1;
	a = -1;
	f = 0;
	if (ft_strlen(little) == 0)
		return (char *)(big);
	while (big[++c])
	{
		while (big[c + f] == little[++a] && big[c] && little[a])
			f++;
		if (!little[a])
			return (char *)&(big[c + f - ft_strlen(little)]);
		a = -1;
		f = 0;
	}
	return (NULL);
}

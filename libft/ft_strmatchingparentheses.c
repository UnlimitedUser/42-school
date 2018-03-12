/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmatchingparentheses.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 22:21:07 by dsclearo          #+#    #+#             */
/*   Updated: 2017/03/20 22:29:31 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strmatchingparentheses(char *str)
{
	int	a;
	int	p;

	p = 0;
	a = -1;
	while (str[++a])
	{
		if (str[a] == '(')
			p++;
		else if (str[a] == ')')
		{
			if (p == 0)
				return (0);
			p--;
		}
	}
	if (p > 0)
		return (0);
	return (1);
}

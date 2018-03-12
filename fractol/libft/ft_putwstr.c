/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:26:50 by dsclearo          #+#    #+#             */
/*   Updated: 2016/12/11 14:05:12 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwstr(wchar_t const *s)
{
	int	c;

	c = -1;
	if (s)
		while (s[++c])
			ft_putchar(s[c]);
}
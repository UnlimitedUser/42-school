/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 15:29:30 by dsclearo          #+#    #+#             */
/*   Updated: 2016/10/21 16:08:07 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nbr_bits(unsigned int nbr)
{
	int		i;

	i = 1;
	while ((nbr = nbr >> 1))
		i++;
	return (i);
}

static void		do_smt(char *buff, int *i, unsigned int ch)
{
	buff[*i++] = ((ch >> 18) & 7) | 240;
	buff[*i++] = ((ch >> 12) & 63) | 128;
}

static void		putwchart(int wchar, int *len, char *buff)
{
	unsigned int	ch;
	int				n;
	int				i;

	i = 0;
	ch = (unsigned int)wchar;
	n = nbr_bits(ch);
	if (n > 7 && ((*len += 1)))
	{
		if (n > 11 && ((*len += 1)))
		{
			if (n > 16 && ((*len += 2)))
				do_smt(buff, &i, ch);
			else if ((*len += 1))
				buff[i++] = ((ch >> 12) & 15) | 224;
			buff[i++] = ((ch >> 6) & 63) | 128;
		}
		else if ((*len += 1))
			buff[i++] = ((ch >> 6) & 31) | 192;
		buff[i++] = (ch & 63) | 128;
	}
	else if ((*len += 1))
		buff[i++] = ch;
}

void			ft_putchar_fd(int c, int fd)
{
	int		len;
	char	buf[10];

	len = 0;
	putwchart(c, &len, buf);
	buf[len] = '\0';
	write(fd, buf, len);
}

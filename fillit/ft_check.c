/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 16:32:32 by dcaldare          #+#    #+#             */
/*   Updated: 2016/11/21 14:56:18 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_isvalidsize(char *buf)
{
	return (ft_strlen(buf) == 20);
}

int		ft_issquare(char *buf)
{
	int i;

	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '#')
		{
			if (buf[i + 1] == '#')
				if (buf[i + 5] == '#')
					if (buf[i + 6] == '#')
						return (1);
			return (0);
		}
	}
	return (0);
}

int		ft_iscorrect(char *buf)
{
	int		i;
	int		hash;

	i = -1;
	hash = 0;
	while (buf[++i])
	{
		if (buf[i] != '.' && buf[i] != '#' && (i % 5 != 4))
			return (0);
		if (i % 5 == 4 && buf[i] != '\n')
			return (0);
		if (buf[i] == '#')
		{
			if (i - 1 >= 0 && buf[i - 1] == '#')
				hash++;
			if (i - 5 >= 0 && buf[i - 5] == '#')
				hash++;
		}
	}
	if (hash == 4)
		if (ft_issquare(buf))
			return (1);
	return (hash == 3);
}

void	ft_maketetri(char *buf, t_vector (*vectors)[27][4], int c)
{
	int		i;
	int		a;
	int		z;

	a = 0;
	i = 0;
	z = 0;
	while (*buf)
	{
		if (*buf == '#')
		{
			(*vectors)[c][z].x = a;
			(*vectors)[c][z++].y = i;
		}
		if (*(buf) == '\n' && !(i = 0))
		{
			buf++;
			a++;
		}
		else
		{
			i++;
			buf++;
		}
	}
}

int		ft_populate(int fd, t_vector (*vectors)[27][4])
{
	char	buf[B_SIZE + 1];
	int		tetri;
	char	newline;

	tetri = -1;
	buf[20] = '\0';
	newline = '\n';
	while (read(fd, buf, B_SIZE))
	{
		if (++tetri > 26)
			return (0);
		if (ft_isvalidsize(buf) && ft_iscorrect(buf) && !(newline = '\0'))
		{
			ft_maketetri(buf, vectors, tetri);
			if ((!(read(fd, &newline, 1))))
				break ;
			else if (newline != '\n')
				return (0);
		}
		else
			return (0);
		ft_bzero(buf, 20);
	}
	(*vectors)[tetri + 1][0].x = -1;
	return ((newline == '\n') ? 0 : 1);
}

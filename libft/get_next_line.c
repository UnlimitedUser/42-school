/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 20:03:00 by dsclearo          #+#    #+#             */
/*   Updated: 2016/11/24 21:29:21 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					read_buff(int fd, char **str)
{
	char			buf[BUFF_SIZE + 1];
	ssize_t			succes;
	char			*tmp;

	if (!(succes = read(fd, buf, BUFF_SIZE)))
		return (0);
	else if (succes == -1)
		return (-1);
	buf[succes] = '\0';
	tmp = *str;
	if (!(*str = ft_strjoin(*str, buf)))
	{
		free(tmp);
		return (-1);
	}
	free(tmp);
	return (1);
}

int					search(char **current, char **line)
{
	char			*eofn;
	char			*tmp;

	if ((eofn = ft_strchr(*current, '\n')))
	{
		*eofn = '\0';
		tmp = *current;
		if (!(*line = ft_strdup(*current)))
		{
			free(tmp);
			return (-1);
		}
		if (!(*current = ft_strdup(eofn + sizeof(char))))
		{
			free(tmp);
			return (-1);
		}
		free(tmp);
		return (1);
	}
	return (2);
}

int					handle_eof(char **current, char **line)
{
	if (*current && **current)
	{
		if (!(*line = ft_strdup(*current)))
			return (-1);
		ft_memdel((void **)current);
		return (1);
	}
	else
	{
		*line = NULL;
		ft_memdel((void **)current);
		return (0);
	}
}

int					get_next_line(int const fd, char **line)
{
	static char		*files[MAX_FD];
	char			**current;
	int				isterm;
	int				res;

	if (fd < 0 || fd > MAX_FD || !line)
		return (-1);
	current = &files[fd];
	isterm = -1;
	while ((isterm != 0))
	{
		if (*current)
			if ((res = (search(current, line))) == 1 || res == -1)
				return (res);
		if ((isterm = (read_buff(fd, current))) == -1)
		{
			ft_memdel((void **)current);
			return (-1);
		}
	}
	return (handle_eof(current, line));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavalac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:40:30 by apavalac          #+#    #+#             */
/*   Updated: 2017/01/06 16:50:34 by apavalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

size_t	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*byte1;
	const char	*byte2;

	byte1 = (char *)s1;
	byte2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		byte1[i] = byte2[i];
		i++;
	}
	return (s1);
}

void	*ft_memalloc(size_t size)
{
	void	*fresh_mem;

	if (size)
	{
		fresh_mem = (void *)malloc(size);
		if (fresh_mem == NULL)
			return (NULL);
		else
		{
			ft_bzero(fresh_mem, size);
			return (fresh_mem);
		}
	}
	else
		return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < n)
		str[i++] = 0;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*join;

	i = 0;
	j = 0;
	k = 0;
	join = NULL;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if ((join = (char *)malloc((i + j + 1) * sizeof(char))) == NULL)
		return (NULL);
	while (k < i + j)
	{
		if (k < i)
			join[k] = s1[k];
		else
			join[k] = s2[k - i];
		k++;
	}
	join[k] = 0;
	return (join);
}

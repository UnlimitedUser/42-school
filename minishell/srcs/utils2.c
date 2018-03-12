/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavalac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:42:34 by apavalac          #+#    #+#             */
/*   Updated: 2017/01/06 16:50:53 by apavalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] == 0 && s2[i] != 0)
		return (0 - s2[0]);
	else if (s1[i] != 0 && s2[i] == 0)
		return (s1[0]);
	else
		return (0);
}

size_t	ft_putstr(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

size_t	ft_putendl(char const *s)
{
	size_t	i;

	i = 0;
	i = ft_putstr(s);
	ft_putchar('\n');
	return (i + 1);
}

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	if ((new_list = (t_list*)ft_memalloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		new_list->content = NULL;
		new_list->content_size = 0;
	}
	else
	{
		if ((new_list->content = (void *)ft_memalloc(content_size)) != NULL)
			ft_memcpy(new_list->content, content, content_size);
		else
		{
			free(new_list);
			return (NULL);
		}
		new_list->content_size = content_size;
		new_list->next = NULL;
	}
	return (new_list);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*copy;

	i = 0;
	if (!len)
		return (NULL);
	if ((copy = (char *)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	copy[len] = '\0';
	while (i < len)
	{
		copy[i] = s[start + i];
		i++;
	}
	return (copy);
}

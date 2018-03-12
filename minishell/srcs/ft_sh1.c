/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavalac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 11:02:14 by apavalac          #+#    #+#             */
/*   Updated: 2017/01/06 13:23:16 by apavalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char	*ft_getenv(char **env, const char *search)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = ft_strlen(search);
	while (env[i])
	{
		if (ft_strncmp(env[i], search, n) == 0)
			return (env[i] + n + 1);
		i++;
	}
	return (NULL);
}

char	*ft_getlstenv(t_list *env, const char *search)
{
	t_list	*tmp;
	char	*s;
	size_t	n;

	s = NULL;
	tmp = env;
	n = ft_strlen(search);
	while (tmp != NULL)
	{
		s = tmp->content;
		if (ft_strncmp(s, search, n) == 0)
			return (s + n + 1);
		tmp = tmp->next;
	}
	return (NULL);
}

void	free_2d(char **tab_2d)
{
	size_t	i;

	i = 0;
	while (tab_2d[i] != NULL)
	{
		free(tab_2d[i]);
		tab_2d[i] = NULL;
		i++;
	}
	free(tab_2d);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavalac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 11:01:59 by apavalac          #+#    #+#             */
/*   Updated: 2017/01/06 13:08:38 by apavalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

t_list	*ft_lstenv(char **env)
{
	t_list	*lstenv;
	t_list	*lsttmp;
	size_t	i;
	size_t	j;

	lsttmp = NULL;
	lstenv = NULL;
	i = 0;
	j = 0;
	if (env[i] == NULL)
		return (lstenv = ft_lstnew("ENV=-i", 7));
	lsttmp = ft_lstnew(env[j], (ft_strlen(env[j]) + 1));
	lstenv = lsttmp;
	j++;
	while (env[i])
		i++;
	while (j < i)
	{
		lsttmp->next = ft_lstnew(env[j], (ft_strlen(env[j]) + 1));
		lsttmp = lsttmp->next;
		j++;
	}
	return (lstenv);
}

t_list	*inc_env(t_list *env, char *var, char *val)
{
	t_list	*tmp;
	char	*stmp;

	tmp = env;
	stmp = NULL;
	if (env == NULL)
	{
		stmp = ft_strjoin(ft_strjoin(var, "="), val);
		env = ft_lstnew(stmp, (ft_strlen(stmp) + 1));
		return (env);
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	stmp = ft_strjoin(ft_strjoin(var, "="), val);
	tmp->next = ft_lstnew(stmp, (ft_strlen(stmp) + 1));
	return (env);
}

int		ft_strccmp(const char *s1, const char *s2, const char c)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[i] && s2[i] && s1[i] != c && s2[i] != c)
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

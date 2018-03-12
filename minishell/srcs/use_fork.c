/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavalac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 11:02:37 by apavalac          #+#    #+#             */
/*   Updated: 2017/01/06 13:19:19 by apavalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	use_fork(char **path_2d, t_list *env, char **args)
{
	pid_t	father;

	father = 0;
	father = fork();
	if (father > 0)
		wait(0);
	if (father == 0)
		son_proc(path_2d, env, args);
}

void	son_proc(char **path_2d, t_list *env, char **args)
{
	size_t	i;
	char	**env_2d;

	i = 0;
	env_2d = NULL;
	env_2d = envtab(env);
	execve(args[0], args, env_2d);
	if (path_2d)
	{
		while (path_2d[i] != 0 && env)
		{
			execve(ft_strjoin(path_2d[i], args[0]), args, env_2d);
			i++;
		}
	}
	ft_putstr("command not found\n");
	exit(EXIT_SUCCESS);
}

char	**envtab(t_list *env)
{
	char	**env_2d;
	char	*s;
	t_list	*tmp;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	s = NULL;
	env_2d = NULL;
	tmp = NULL;
	if ((env_2d = inittab_2d(env)) == NULL)
		return (NULL);
	tmp = env;
	while (tmp != NULL)
	{
		s = tmp->content;
		len = ft_strlen(s) + 1;
		if ((env_2d[i] = (char *)malloc(len * sizeof(char))) == NULL)
			return (NULL);
		env_2d[i] = ft_strcpy(env_2d[i], s);
		tmp = tmp->next;
		i++;
	}
	return (env_2d);
}

char	**inittab_2d(t_list *env)
{
	char	**env_2d;
	t_list	*tmp;
	size_t	i;

	i = 0;
	tmp = env;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	if ((env_2d = (char **)malloc((i + 1) * sizeof(char *))) == NULL)
		return (NULL);
	else
		return (env_2d);
}

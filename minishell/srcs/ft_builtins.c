/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavalac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 11:01:47 by apavalac          #+#    #+#             */
/*   Updated: 2017/01/06 16:34:17 by apavalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		ft_builtins(char **args, t_list *env, int t)
{
	if (ft_strcmp(args[0], "exit") == 0 || t == 0)
		exit(EXIT_SUCCESS);
	else if (ft_strcmp(args[0], "cd") == 0)
		return (exec_cd(args, env));
	else if (ft_strcmp(args[0], "env") == 0)
		return (ft_print_env(env));
	else if (ft_strcmp(args[0], "setenv") == 0)
		return (ft_setenv(env, args));
	else if (ft_strcmp(args[0], "unsetenv") == 0)
		return (ft_unsetenv(env, args));
	return (0);
}

int		ft_print_env(t_list *env)
{
	char	*s;
	t_list	*tmp;

	s = NULL;
	tmp = env;
	while (tmp != NULL)
	{
		s = tmp->content;
		if (s != NULL)
			ft_putendl(s);
		tmp = tmp->next;
	}
	return (1);
}

int		ft_setenv(t_list *env, char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
		i++;
	if (i != 3)
	{
		ft_putstr("setenv requires two arguments\n");
		return (1);
	}
	if (env != NULL)
		ft_putendl("under implementation");
	return (1);
}

int		ft_unsetenv(t_list *env, char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
		i++;
	if (i != 2)
	{
		ft_putstr("unsetenv requires one arguments\n");
		return (1);
	}
	if (env != NULL)
		ft_putendl("under implementation");
	return (1);
}

extern char *g_currdir;

int		exec_cd(char **args, t_list *env)
{
	if (args[1] == NULL)
	{
		g_currdir = ft_getlstenv(env, "HOME");
		if (chdir(ft_getlstenv(env, "HOME")) < 0)
			perror("erreur");
	}
	else if (chdir(args[1]) < 0)
		perror("erreur");
	else
	{
		if (args[1][0] == '.' && args[1][1] == '.')
			g_currdir = ft_strsub(g_currdir, 0, ft_strbchr(g_currdir, '/'));
		else if (!(args[1][0] == '.' && !args[1][1]))
			g_currdir = ft_strjoin(g_currdir, ft_strjoin("/", args[1]));
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavalac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 11:02:26 by apavalac          #+#    #+#             */
/*   Updated: 2017/01/06 13:50:00 by apavalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char *g_currdir;

int		main(int argc, char **argv, char **env)
{
	char	*path;
	char	**path_2d;
	t_list	*lstenv;

	argc = 0;
	argv = NULL;
	path = NULL;
	path_2d = NULL;
	lstenv = NULL;
	path = ft_getenv(env, "PATH");
	g_currdir = ft_getenv(env, "PWD");
	lstenv = ft_lstenv(env);
	path_2d = ft_strsplit(path, ':');
	if (path_2d)
		path_2d = ft_slashpath(path_2d);
	while (1)
	{
		if (infinit_loop(path_2d, lstenv) == -1)
			return (0);
	}
}

char	**ft_slashpath(char **path_2d)
{
	size_t	i;

	i = 0;
	while (path_2d[i])
	{
		path_2d[i] = ft_strjoin(path_2d[i], "/");
		i++;
	}
	return (path_2d);
}

char **g_comms;
int g_i;

int		infinit_loop(char **path_2d, t_list *env)
{
	char	buff[BUFF_SIZE];
	char	**args;
	size_t	t;
	int		memory;

	memory = 0;
	args = NULL;
	ft_putstr("$ ");
	ft_putstr(g_currdir);
	ft_putstr("> ");
	signal(SIGINT, &func);
	t = read(0, buff, BUFF_SIZE);
	buff[t - 1] = 0;
	g_comms = ft_strsplit(buff, ';');
	g_i = -1;
	while (g_comms[++g_i])
	{
		args = ft_strsplit(g_comms[g_i], ' ');
		memory = ft_builtins(args, env, t);
		if (memory != 1)
			use_fork(path_2d, env, args);
		free_2d(args);
	}
	free_2d(g_comms);
	return (0);
}

void	func(int i)
{
	(void)i;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavalac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 11:01:00 by apavalac          #+#    #+#             */
/*   Updated: 2017/01/06 16:38:43 by apavalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

# define BUFF_SIZE 1024

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
t_list				*ft_lstnew(void const *content, size_t content_size);
char				*ft_getenv(char **env, const char *search);
char				*ft_getlstenv(t_list *env, const char *search);
void				free_2d(char **tab_2d);
char				**ft_slashpath(char **path_2d);
int					ft_builtins(char **args, t_list *env, int t);
int					ft_print_env(t_list *env);
int					ft_setenv(t_list *env, char **args);
int					ft_unsetenv(t_list *env, char **args);
int					exec_cd(char **args, t_list *env);
t_list				*ft_lstenv(char **env);
t_list				*inc_env(t_list *env, char *var, char *val);
t_list				*del_env(t_list *env, char *var);
int					infinit_loop(char **path_2d, t_list *env);
void				use_fork(char **path_2d, t_list *env, char **args);
void				son_proc(char **path_2d, t_list *env, char **args);
char				**envtab(t_list *env);
char				**inittab_2d(t_list *env);
void				func(int i);
char				**ft_strsplit(char const *s, char c);
int					ft_strccmp(const char *s1, const char *s2, const char c);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_putstr(char const *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *s1, const char *s2);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_putendl(char const *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
size_t				ft_putchar(char c);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
int					ft_strbchr(char *s, int a);

#endif

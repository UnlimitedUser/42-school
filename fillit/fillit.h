/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 15:50:58 by dsclearo          #+#    #+#             */
/*   Updated: 2016/11/21 15:04:43 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define B_SIZE 20

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_vector
{
	int				x;
	int				y;
}					t_vector;

void				*ft_memset(void *b, int c, size_t len);
int					ft_populate(int fd, t_vector (*vectors)[27][4]);
int					ft_put_in_right_corner(t_vector (*vectors)[27][4]);
void				ft_print_map(char **map);
void				ft_memdela(void ***mem);
void				**ft_memalloca(int row);
char				**ft_init_solve(t_vector vectors[27][4], int tetris);
int					ft_vert(t_vector vectors[26][4], int nr);
int					ft_oriz(t_vector vectors[26][4], int nr);
char				**ft_newmap(void);
int					g_size;
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);
void				ft_putchar(int c);
size_t				ft_strlen(const char *str);
void				ft_putstr(const char *str);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 14:00:22 by dsclearo          #+#    #+#             */
/*   Updated: 2017/03/22 13:27:36 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

# define BUFF_SIZE 32
# define MAX_FD 4864
# define MININT -2147483648
# define MAXINT 2147483647

# define ABS(x) (((x) < (0)) ? (-x) : (x))
# define MAX(x, y) (((x) > (y)) ? (x) : (y))
# define MIN(x, y) (((x) < (y)) ? (x) : (y))

int						ft_printf(const char *format, ...);
int						get_next_line(int const fd, char **line);

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_btree
{
	struct s_btree		*left;
	struct s_btree		*right;
	void				*item;
}						t_btree;

char					*ft_uintmax_ttoa_base_upper(uintmax_t n, int base);
char					*ft_uintmax_ttoa_base(uintmax_t n, int base);
char					*ft_uintmax_ttoa(uintmax_t n);
char					*ft_intmax_ttoa(intmax_t n);
int						ft_intmax_tlen(intmax_t num);
unsigned int			ft_chrlen(int chr);
size_t					ft_wstrlen(wchar_t const *str);
void					ft_putnwstr(wchar_t const *s, size_t c);
void					ft_putwstr(wchar_t const *s);
void					ft_putwstr_fd(wchar_t const *s, int fd);
void					ft_putnstr(const char *str, size_t len);
void					ft_putnstr_fd(char const *str, size_t str_len, int fd);
char					*ft_strrchr(const char *s, int c);
size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *s1);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_atoi(const char *str);
char					*ft_strstr(const char *big, const char *little);
char					*ft_strnstr(const char *big, const char *little,
		size_t len);
void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src, int c,
		size_t n);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t n);
void					ft_putchar(int c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(int c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
char					*ft_strjoin(char const *s1, char const *s2);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void(*f) (char*));
void					ft_striteri(char *s, void(*f) (unsigned int, char *));
char					*ft_strmap(char const *s, char(*f) (char));
char					*ft_strmapi(char const *s,
		char (*f) (unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start,
		size_t len);
void					*ft_memmove(void *dst, const void *src, size_t len);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
char					*ft_itoa(int n);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
void					*ft_memchr(const void *s, int c, size_t n);
char					*ft_strchr(const char *s, int c);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst,
		void (*del)(void *, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char					*ft_strrev(char *str);
int						ft_numlen(int num);
int						is_lower(char a);
char					*ft_strtoupper(char *str);
int						ft_isupper(char a);
char					*ft_strtolower(char *str);
int						ft_any(char **tab, int (*f)(char*));
int						*ft_map(int *tab, int length, int (*f)(int));
void					ft_foreach(int *tab, int length, void (*f)(int));
int						ft_count_if(char **tab, int (*f)(char*));
int						ft_is_sort(int *tab, int length, int (*f)(int, int));
int						ft_isprime(int nbr);
int						*ft_range(int min, int max);
int						ft_ultimate_range(int **range, int min, int max);
int						ft_nextprime(int nbr);
void					ft_btree_apply_infix(t_btree *root,
		void (*applyf)(void *));
t_btree					*ft_btree_create_node(void *item);
void					ft_btree_apply_prefix(t_btree *root,
		void (*applyf)(void *));
void					print_spaces(size_t nr);
void					ft_lstsort(t_list *list,
		int(*cmp)(t_list *, t_list *));
void					ft_lstreverse(t_list **list);
void					ft_printarr(int arr[], int n);
void					ft_arrinsertionsort(int arr[], int n);
void					ft_arrselectionsort(int arr[], int n);
int						ft_arrlinearsearch(int arr[], int n, int tosearch);
void					ft_arrrecursiveinsertionsort(int arr[], int n);
int						ft_arrrecursivebinarysearch(int arr[],
		int n, int tofind);
int						ft_arrbinarysearch(int arr[], int n, int tofind);
void					ft_arrmergesort(int arr[], int n);
int						ft_arrfindmaxsubarr(int arr[], int n,
		int *start, int *end);
void					ft_swap(void *a, void *b);
void					ft_heapinsert(int heap[], int *n, int num);
int						ft_heapparent(int heap[], int size, int n);
int						ft_heapfirstchild(int heap[], int size, int n);
int						ft_heapextract(int heap[], int *n);
void					ft_heapswap(int heap[], int n, int a, int b);
void					ft_heapbubble_up(int heap[], int size, int n);
void					ft_heapbubble_down(int heap[], int n, int index);
void					ft_arrheapsort(int arr[], int n);
void					ft_arrquicksort(int arr[], int n);

#endif

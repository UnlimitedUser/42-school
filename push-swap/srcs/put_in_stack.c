#include "../includes/push_swap.h"

static int		count(char **res)
{
	int		c;

	c = 0;
	while (res[c])
		c++;
	return (c);
}

static int		has_dublicates(t_stack st_a)
{
	int		i;
	int		a;

	i = -1;
	while (++i < st_a.top)
	{
		a = i;
		while (++a <= st_a.top)
			if (st_a.arr[a] == st_a.arr[i])
				return (1);
	}
	return (0);
}

char			*skip_zero(char *str)
{
	if (*str == '0' && !*(str + 1))
		return (str);
	while (*str == '0')
		str++;
	return (str);
}

void			put_in_stack(t_stack *st_a, int ac, char **av)
{
	char	**res;
	int		c;
	int		num;

	while (--ac > 0)
	{
		res = ft_strsplit(av[ac], ' ');
		c = count(res);
		while (--c > -1)
		{
			if (!ft_strcmp(ft_itoa(num = ft_atoi(res[c])), skip_zero(res[c])))
				st_a->arr[++st_a->top] = num;
			else
				exit_on_error();
		}
	}
	if (has_dublicates(*st_a))
		exit_on_error();
}

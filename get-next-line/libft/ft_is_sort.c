/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsclearo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 13:54:58 by dsclearo          #+#    #+#             */
/*   Updated: 2016/09/12 14:26:43 by dsclearo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	c;
	int sort1;
	int	sort2;

	sort1 = 1;
	sort2 = 1;
	c = -1;
	while (++c < length - 1)
	{
		if (f(tab[c], tab[c + 1]) > 0)
		{
			sort1 = 0;
		}
	}
	c = -1;
	while (++c < length - 1)
	{
		if (f(tab[c], tab[c + 1]) < 0)
		{
			sort2 = 0;
		}
	}
	return (sort1 || sort2);
}

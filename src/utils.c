/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:37:31 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/02 17:10:43 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		max(int a, int b)
{
	return (a > b) ? a : b;
}

int		integer_len(int n)
{
	int	len;

	len = 1;
	while (n / 10)
	{
		n /= 10;
		++len;
	}
	return (len);
}

int		lst_maxlen(t_file *lst)
{
	int		maxlen;

	maxlen = 0;
	while (lst)
	{
		maxlen = max(ft_strlen(lst->name), maxlen);
		lst = lst->next;
	}
	return (maxlen);
}

t_file	*lst_swap(t_file *p1, t_file *p2)
{
	p1->next = p2->next;
	p2->next = p1;
	return (p2);
}

void	print_space(int n, int a)
{
	int i;

	i = (n > a) ? (n - a) : (a - n);
	while (i--)
		ft_printf(" ");
}

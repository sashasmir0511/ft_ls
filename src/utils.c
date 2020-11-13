//
// Created by alex on 13.11.2020.
//
#include "ft_ls.h"

int 	MAX(int a, int b)
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
		maxlen = MAX(ft_strlen(lst->name), maxlen);
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

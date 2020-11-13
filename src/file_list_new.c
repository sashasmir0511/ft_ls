/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list_new.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired  <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 03:10:19 by lhaired           #+#    #+#             */
/*   Updated: 2020/11/13 04:45:18 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

int		ft_sort_tab(char **tab, int size,
			int (*f)(const char*, const char*))
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	while (j < size)
	{
		i = j - 1;
		tmp = tab[j];
		while (i >= 0 && f(tab[i], tmp) > 0)
		{
			tab[i + 1] = tab[i];
			i--;
		}
		tab[i + 1] = tmp;
		j++;
	}
	return (1);
}

t_file	*file_list_new(int argc, char **argv, int fl)
{
	t_file	*begin;
	int		i;

	begin = NULL;
	if (!argc)
		add_new_file("", ".", &begin);
	else
		ft_sort_tab(argv, argc, &ft_strcmp);
	i = -1;
	while (++i < argc)
		if (add_new_file("", argv[i], &begin) == -1 && fl)
			error(argv[i], ERRNO);
	return (begin);
}
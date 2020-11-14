/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_detailed_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:37:31 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/02 17:10:43 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	get_row_size(t_file *file, int *size, int *blocks)
{
	int	len;

	size[5] = 3;
	size[6] = 3;
	while (file)
	{
		size[0] = max(integer_len(file->st_blocks), size[0]);
		size[1] = max(integer_len(file->st_nlink), size[1]);
		size[2] = max(ft_strlen(getpwuid(file->st_uid)->pw_name), size[2]);
		size[3] = max(ft_strlen(getgrgid(file->st_gid)->gr_name), size[3]);
		if (!S_ISCHR(file->mode))
			len = integer_len(file->size);
		else
		{
			size[5] = max(integer_len(major(file->st_rdev)), size[5]);
			size[6] = max(integer_len(minor(file->st_rdev)), size[6]);
			len = size[5] + size[6] + 2;
		}
		size[4] = max(len, size[4]);
		*blocks += file->st_blocks;
		file = file->next;
	}
	size[5] = max(size[4] - size[6] - 1, size[5]);
	return (1);
}

int			display_detailed_list(t_file *lst, int flags)
{
	int	size[7];
	int	blocks;
	int	first;

	ft_bzero(size, sizeof(size));
	blocks = 0;
	first = 1;
	get_row_size(lst, size, &blocks);
	while (lst)
	{
		if (first == 1 && !(flags & LS_D))
		{
			ft_printf("total %d\n", blocks);
			first = 0;
		}
		display_list_items(lst, size, flags);
		ft_putchar('\n');
		lst = lst->next;
	}
	return (1);
}

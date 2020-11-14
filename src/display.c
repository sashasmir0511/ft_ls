/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:37:31 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/02 17:10:43 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_file	*read_folder(char path[PATH_MAX], int options)
{
	t_file			*begin;
	DIR				*folder;
	t_dirent		*entry;

	begin = NULL;
	if (!(folder = opendir(path)))
		error();
	else if (!(options & LS_D))
	{
		while ((entry = readdir(folder)))
			if (entry->d_name[0] != '.' || (options & LS_A))
				add_new_file(path, entry->d_name, &begin);
	}
	else
		add_new_file(path, ".", &begin);
	if (folder)
		closedir(folder);
	return (begin);
}

static void		display_full_path(char *full_path, int number, int *first)
{
	if (number != 0 && number != 1)
	{
		if (*first == 2)
		{
			*first = 1;
			ft_printf("%s:\n", full_path);
		}
		else
			ft_printf("\n%s:\n", full_path);
	}
}

int				display(t_file *begin, int flags, int first, int n)
{
	t_file	*file;

	file = begin;
	if (!(flags & LS_RR) && !first)
		return (1);
	while (file)
	{
		if (S_ISDIR(file->mode) && (first || (ft_strcmp(file->name, ".")
		&& ft_strcmp(file->name, ".."))))
		{
			display_full_path(file->full_path, n, &first);
			begin = read_folder(file->full_path, flags);
			if (begin)
			{
				display_list(&begin, flags);
				display(begin, flags, 0, -1);
				free_list_content(&begin);
			}
		}
		file = file->next;
	}
	return (1);
}

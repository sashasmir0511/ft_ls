/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list_items.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:37:31 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/02 17:10:43 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		get_file_type(int mode)
{
	mode = (mode & S_IFMT);
	if (S_ISREG(mode))
		return ('-');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISFIFO(mode))
		return ('p');
	else
		return ('-');
}

static void		display_chmod(char chmod[11], int mode)
{
	chmod[0] = get_file_type(mode);
	chmod[1] = (S_IRUSR & mode) ? 'r' : '-';
	chmod[2] = (S_IWUSR & mode) ? 'w' : '-';
	chmod[3] = (S_IXUSR & mode) ? 'x' : '-';
	chmod[4] = (S_IRGRP & mode) ? 'r' : '-';
	chmod[5] = (S_IWGRP & mode) ? 'w' : '-';
	chmod[6] = (S_IXGRP & mode) ? 'x' : '-';
	chmod[7] = (S_IROTH & mode) ? 'r' : '-';
	chmod[8] = (S_IWOTH & mode) ? 'w' : '-';
	chmod[9] = (S_IXOTH & mode) ? 'x' : '-';
	chmod[10] = '\0';
	if (S_ISUID & mode)
		chmod[3] = chmod[3] == '-' ? 'S' : 's';
	if (S_ISGID & mode)
		chmod[6] = chmod[6] == '-' ? 'S' : 's';
	if (S_ISVTX & mode)
		chmod[9] = chmod[9] == '-' ? 'T' : 't';
	ft_putstr(chmod);
}

static void		display_time(t_file *file)
{
	time_t	today;
	char	*s;

	time(&today);
	s = ctime(&(file->time)) + 4;
	ft_printf(" %.12s ", s);
}

static void		display_list_items_part2(t_file *file, int size[7], int flags,
											char str[12])
{
	char	buf[NAME_MAX + 1];

	if (str[0] != 'c' && str[0] != 'b')
	{
		print_space(size[4], integer_len(file->size));
		ft_printf(" %lld", file->size);
	}
	else
	{
		print_space(size[5], integer_len(major(file->st_rdev)));
		ft_printf(" %d", major(file->st_rdev));
		print_space(size[6], integer_len(minor(file->st_rdev)));
		ft_printf(", %d", minor(file->st_rdev));
	}
	display_time(file);
	if (str[0] != 'l')
		display_name(file, flags, 0);
	else
	{
		ft_bzero(buf, NAME_MAX + 1);
		readlink(file->full_path, buf, NAME_MAX);
		ft_printf("%s -> %s", file->name, buf);
	}
}

int				display_list_items(t_file *file, int size[7], int flags)
{
	char	str[12];

	if (flags & LS_S)
	{
		print_space(size[0], integer_len(file->st_blocks));
		ft_printf("%u ", file->st_blocks);
	}
	display_chmod(str, file->mode);
	print_space(size[1], integer_len(file->st_nlink));
	ft_printf(" %u", file->st_nlink);
	ft_printf(" %s", getpwuid(file->st_uid)->pw_name);
	print_space(size[2], ft_strlen(getpwuid(file->st_uid)->pw_name));
	ft_printf("  %s", getgrgid(file->st_gid)->gr_name);
	print_space(size[3], ft_strlen(getgrgid(file->st_gid)->gr_name));
	display_list_items_part2(file, size, flags, str);
	return (1);
}

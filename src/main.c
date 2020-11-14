/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:37:31 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/02 17:10:43 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	int			i;
	int			flags;
	t_file		*file_lst;

	if ((i = parsing(argc, argv, &flags)) == -1)
		return (1);
	file_lst = file_list_new(argc - i, argv + i, 1);
	display(file_lst, flags, (file_lst ? 1 : 2), argc - i);
	free_list_content(&file_lst);
	return (0);
}

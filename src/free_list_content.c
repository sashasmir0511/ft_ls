/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:37:31 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/02 17:10:43 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		free_list_content(t_file **lst)
{
	while (*lst)
	{
		free((*lst)->name);
		free(*lst);
		*lst = (*lst)->next;
	}
	return (1);
}

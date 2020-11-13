/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_no_ascii.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:11:52 by lhaired           #+#    #+#             */
/*   Updated: 2019/09/02 16:13:48 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp_no_ascii(char *s1, char *s2)
{
	char	c1;
	char	c2;

	c1 = ft_isupper(*s1) ? *s1 : *s1 + 'A' - 'a';
	c2 = ft_isupper(*s2) ? *s2 : *s2 + 'A' - 'a';
	while (*s1 && *s2 && c1 == c2)
	{
		s1++;
		s2++;
		c1 = ft_isupper(*s1) ? *s1 : *s1 + 'A' - 'a';
		c2 = ft_isupper(*s2) ? *s2 : *s2 + 'A' - 'a';
	}
	return ((unsigned char)c1 - (unsigned char)c2);
}

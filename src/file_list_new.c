#include "ft_ls.h"


t_file		*file_list_new(int argc, char** argv, int fl)
{
	t_file	*begin;
	int		i;

	begin = NULL;
	if (ac == 0)
		add_new_file("", ".", &begin);
	else
		ft_sort_tab(argv, ac, &ft_strcmp);
	i = 0;
	while (i < ac)
	{
		if (add_new_file("", argv[i], &begin) == -1 && fl)
			error();
		i++;
	}
	return (begin);
}

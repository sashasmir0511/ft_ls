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
#include <ft_ls.h>

int main(int argc, char **argv)
{
	int			i;
	int			flags;
	t_file		*file_lst;

	if ((i = parsing(argc, argv, &flags)) == -1)
		return (1);
//	ft_printf("%d\n", flags);
	file_lst = file_list_new(argc - i, argv + i, 1);
	
	return (0);
}

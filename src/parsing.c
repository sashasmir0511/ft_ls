#include <ft_ls.h>

static int	ft_strchr_index(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

static int	parse_options(char *s, int *fl)
{
	int		n;

	s++;
	while (*s)
	{
		if ((n = ft_strchr_index("alRrtdg1Ss", *s)) == -1)
			error();
		*fl = *fl | (1 << n);
		if ((*s == 'l') || (*s == '1'))
			*fl &= (*s == 'l') ? ~LS_ONE : ~LS_L;
		s++;
	}
	return (1);
}

int			parsing(int argc, char **argv, int *flags)
{
	int		i;

	*flags = 0;
	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1])
	{
		if (argv[i][1] == '-' && argv[i][2])
			return (i + 1);
		if (!parse_options(argv[i], flags))
			return (-1);
		i++;
	}
	return (i);
}


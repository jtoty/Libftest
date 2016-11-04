#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

void	ft_print_result(char const *s)
{
	while (*s)
	{
		write(1, &*s, 1);
		s++;
	}
}

int		main(int argc, const char *argv[])
{
	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		char	str[] ="LOREM IPSUM DOLOR SIT AMET";
		ft_print_result(ft_strlowcase(str));
	}
	else if (atoi(argv[1]) == 2)
	{
		char	str[] =" \n\tlorem 4ipSum DOLOR s\nit aMeT ";
		ft_print_result(ft_strlowcase(str));
	}
	else if (atoi(argv[1]) == 3)
	{
		char	str[] ="HeY ! 42mots quArAnte-deux; cinquante+et+un";
		ft_print_result(ft_strlowcase(str));
	}
	return (0);
}

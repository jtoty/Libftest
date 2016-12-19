#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int		main(int argc, const char *argv[])
{
	int		arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		char	str[] ="lorem ipsum dolor sit amet";
		ft_print_result(ft_strupcase(str));
	}
	else if (arg == 2)
	{
		char	str[] =" \n\tlorem 4ipSum DOLOR s\nit aMeT ";
		ft_print_result(ft_strupcase(str));
	}
	else if (arg == 3)
	{
		char	str[] ="HeY ! 42mots quArAnte-deux; cinquante+et+un";
		ft_print_result(ft_strupcase(str));
	}
	return (0);
}

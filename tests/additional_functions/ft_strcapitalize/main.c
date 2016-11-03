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
		char str[] = "  lorem IPsuM dOlor sit amet  ";
		ft_print_result(ft_strcapitalize(str));
	}
	else if (atoi(argv[1]) == 2)
	{
		char str[] = " \n\tlorem 4ipsum DOLOR s\nit aMeT ";
		ft_print_result(ft_strcapitalize(str));
	}
	else if (atoi(argv[1]) == 3)
	{
		char str[] = "salut, comment tu vas ? 42mots trente-deux; vingt+et+un";
		ft_print_result(ft_strcapitalize(str));
	}
	return (0);
}

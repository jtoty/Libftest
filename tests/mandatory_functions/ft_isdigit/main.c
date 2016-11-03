#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "../../../libft.h"

void	ft_print_result(int n)
{
	if (n)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

int		main(int argc, const char *argv[])
{
	int i;

	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		i = 0;
		while (i <= 47)
		{
			ft_print_result(ft_isdigit(i));
			i++;
		}
	}
	else if (atoi(argv[1]) == 2)
	{
		i = '0';
		while (i <= '9')
		{
			ft_print_result(ft_isdigit(i));
			i++;
		}
	}
	else if (atoi(argv[1]) == 3)
	{
		i = 58;
		while (i <= 64)
		{
			ft_print_result(ft_isdigit(i));
			i++;
		}
	}
	else if (atoi(argv[1]) == 4)
	{
		i = 'A';
		while (i <= 'Z')
		{
			ft_print_result(ft_isdigit(i));
			i++;
		}
	}
	else if (atoi(argv[1]) == 5)
	{
		i = 91;
		while (i <= 96)
		{
			ft_print_result(ft_isdigit(i));
			i++;
		}
	}
	else if (atoi(argv[1]) == 6)
	{
		i = 'a';
		while (i <= 'z')
		{
			ft_print_result(ft_isdigit(i));
			i++;
		}
	}
	else if (atoi(argv[1]) == 7)
	{
		i = 123;
		while (i <= 127)
		{
			ft_print_result(ft_isdigit(i));
			i++;
		}
	}
	return (0);
}

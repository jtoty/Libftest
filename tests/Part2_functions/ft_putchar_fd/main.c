#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

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
			ft_putchar_fd(i, 2);
			i++;
		}
	}
	else if (atoi(argv[1]) == 2)
	{
		i = '0';
		while (i <= '9')
		{
			ft_putchar_fd(i, 1);
			i++;
		}
	}
	else if (atoi(argv[1]) == 3)
	{
		i = 58;
		while (i <= 64)
		{
			ft_putchar_fd(i, 2);
			i++;
		}
	}
	else if (atoi(argv[1]) == 4)
	{
		i = 'A';
		while (i <= 'Z')
		{
			ft_putchar_fd(i, 1);
			i++;
		}
	}
	else if (atoi(argv[1]) == 5)
	{
		i = 91;
		while (i <= 96)
		{
			ft_putchar_fd(i, 2);
			i++;
		}
	}
	else if (atoi(argv[1]) == 6)
	{
		i = 'a';
		while (i <= 'z')
		{
			ft_putchar_fd(i, 1);
			i++;
		}
	}
	else if (atoi(argv[1]) == 7)
	{
		i = 123;
		while (i <= 127)
		{
			ft_putchar_fd(i, 2);
			i++;
		}
	}
	return (0);
}

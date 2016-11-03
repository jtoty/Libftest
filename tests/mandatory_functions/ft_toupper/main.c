#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "../../../libft.h"

int		main(int argc, const char *argv[])
{
	int i;
	int c;

	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		i = 0;
		while (i <= 47)
		{
			c = ft_toupper(i);
			write(1, &c, 1);
			i++;
		}
	}
	else if (atoi(argv[1]) == 2)
	{
		i = '0';
		while (i <= '9')
		{
			c = ft_toupper(i);
			write(1, &c, 1);
			i++;
		}
	}
	else if (atoi(argv[1]) == 3)
	{
		i = 58;
		while (i <= 64)
		{
			c = ft_toupper(i);
			write(1, &c, 1);
			i++;
		}
	}
	else if (atoi(argv[1]) == 4)
	{
		i = 'A';
		while (i <= 'Z')
		{
			c = ft_toupper(i);
			write(1, &c, 1);
			i++;
		}
	}
	else if (atoi(argv[1]) == 5)
	{
		i = 91;
		while (i <= 96)
		{
			c = ft_toupper(i);
			write(1, &c, 1);
			i++;
		}
	}
	else if (atoi(argv[1]) == 6)
	{
		i = 'a';
		while (i <= 'z')
		{
			c = ft_toupper(i);
			write(1, &c, 1);
			i++;
		}
	}
	else if (atoi(argv[1]) == 7)
	{
		i = 123;
		while (i <= 127)
		{
			c = ft_toupper(i);
			write(1, &c, 1);
			i++;
		}
	}
	return (0);
}

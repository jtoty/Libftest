#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"
#include <limits.h>

int		main(int argc, const char *argv[])
{
	char	*str;
	int		i;

	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		str = ft_memalloc(9);
		if (!str)
		{
			write(1, "NULL", 4);
			return (0);
		}
		i = 0;
		while (i < 9)
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	else if (atoi(argv[1]) == 2)
	{
		str = ft_memalloc(ULONG_MAX);
		if (!str)
		{
			write(1, "NULL", 4);
			return (0);
		}
		i = 0;
		while (i < 9)
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	else if (atoi(argv[1]) == 3)
	{
		str = ft_memalloc(0);
		if (!str)
			write(1, "NULL", 4);
	}
	return (0);
}

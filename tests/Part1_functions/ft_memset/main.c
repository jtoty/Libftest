#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../../libft.h"

int		main(int argc, const char *argv[])
{
	void	*mem;
	int		arg;

	if (!(mem = malloc(sizeof(*mem) * 15)) || argc == 1)
		return (0);
	memset(mem, 'j', 15);
	if ((arg = atoi(argv[1])) == 1)
	{
		if (mem != ft_memset(mem, 'c', 5))
			write(1, "mem's adress was not returned\n", 30);
		write(1, mem, 15);
	}
	else if (arg == 2)
	{
		if (mem != ft_memset(mem, 'c', 14))
			write(1, "mem's adress was not returned\n", 30);
		write(1, mem, 15);
	}
	else if (arg == 3)
	{
		if (mem != ft_memset(mem, '\n', 6))
			write(1, "mem's adress was not returned\n", 30);
		write(1, mem, 15);
	}
	else if (arg == 4)
	{
		if (mem != ft_memset(mem, '\0', 1))
			write(1, "mem's adress was not returned\n", 30);
		write(1, mem, 15);
	}
	return (0);
}

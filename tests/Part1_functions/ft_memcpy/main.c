#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../../libft.h"

void	ft_print_result(char const *s, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		write (1, &s[i], 1);
		i++;
	}
}

int		main(int argc, const char *argv[])
{
	void	*mem;

	if (!(mem = malloc(sizeof(*mem) * 30)) || argc == 1)
		return (0);
	memset(mem, 'j', 30);
	if (atoi(argv[1]) == 1)
	{
		if (mem != ft_memcpy(mem, "zyxwvutsrqponmlkjihgfedcba", 14))
			ft_print_result("dest's adress was not returned\n", 31);
		ft_print_result(mem, 30);
	}
	else if (atoi(argv[1]) == 2)
	{
		if (mem != ft_memcpy(mem, "zyxwvutst", 0))
			ft_print_result("dest's adress was not returned\n", 31);
		ft_print_result(mem, 30);
	}
	else if (atoi(argv[1]) == 3)
	{
		if (mem != ft_memcpy(mem, "zy\0xw\0vu\0\0tsr", 11))
			ft_print_result("dest's adress was not returned\n", 31);
		ft_print_result(mem, 30);
	}
	return (0);
}

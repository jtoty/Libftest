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

	if (!(mem = malloc(sizeof(*mem) * 15)) || argc == 1)
		return (0);
	memset(mem, 'j', 15);
	if (atoi(argv[1]) == 1)
	{
		ft_memset(mem, 'c', 5);
		ft_print_result(mem, 15);
	}
	else if (atoi(argv[1]) == 2)
	{
		ft_memset(mem, 'c', 14);
		ft_print_result(mem, 15);
	}
	else if (atoi(argv[1]) == 3)
	{
		ft_memset(mem, '\n', 6);
		ft_print_result(mem, 15);
	}
	else if (atoi(argv[1]) == 4)
	{
		ft_memset(mem, '\0', 1);
		ft_print_result(mem, 15);
	}
	return (0);
}

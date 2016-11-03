#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include "../../../libft.h"

void	ft_print_result(char const *s, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		write(1, &s[i], 1);
		i++;
	}
}

int		main(int argc, const char *argv[])
{
	void	*mem;

	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		if (!(mem = malloc(sizeof(*mem) * 5)))
			return (0);
		ft_bzero(mem, 5);
		ft_print_result(mem, 5);
	}
	else if (atoi(argv[1]) == 2)
	{
		if (!(mem = malloc(sizeof(*mem) * 10)))
			return (0);
		ft_bzero(mem, 10);
		ft_print_result(mem, 10);
	}
	else if (atoi(argv[1]) == 3)
	{
		if (!(mem = malloc(sizeof(*mem) * 15)))
			return (0);
		ft_bzero(mem, 15);
		ft_print_result(mem, 15);
	}
	else if (atoi(argv[1]) == 4)
	{
		if (!(mem = malloc(sizeof(*mem) * 100)))
			return (0);
		ft_bzero(mem, 100);
		ft_print_result(mem, 100);
	}
	else if (atoi(argv[1]) == 5)
	{
		if (!(mem = malloc(sizeof(*mem) * 1000)))
			return (0);
		ft_bzero(mem, 1000);
		ft_print_result(mem, 1000);
	}
	return (0);
}

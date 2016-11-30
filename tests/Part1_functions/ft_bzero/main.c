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
		write(1, &s[i], 1);
		i++;
	}
}

int		main(int argc, const char *argv[])
{
	void	*mem;

	if (argc == 1 || !(mem = malloc(sizeof(*mem) * 5)))
		return (0);
	if (atoi(argv[1]) == 1)
	{
		ft_bzero(mem, 5);
		ft_print_result(mem, 5);
	}
	else if (atoi(argv[1]) == 2)
	{
		memset(mem, 'e', 5);
		ft_bzero(mem, 0);
		ft_print_result(mem, 5);
	}
	return (0);
}

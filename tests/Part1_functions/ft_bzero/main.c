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
	return (0);
}

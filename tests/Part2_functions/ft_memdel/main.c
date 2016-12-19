#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

int		main(int argc, const char *argv[])
{
	void	*mem;

	mem = malloc(sizeof(*mem) * 10);
	if (argc == 1 || !mem)
		return (0);
	else if (atoi(argv[1]) == 1)
	{
		ft_memdel(&mem);
		if (!mem)
			write(1, "NULL", 4);
		else
			write(1, "NOT NULL", 8);
	}
	return (0);
}

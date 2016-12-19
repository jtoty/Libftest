#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

int		main(int argc, const char *argv[])
{
	int		arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		ft_putendl("lorem ipsum dolor sit amet");
	else if (arg == 2)
		ft_putendl("  lorem\nipsum\rdolor\tsit amet  ");
	else if (arg == 3)
		ft_putendl("");
	else if (arg == 4)
		ft_putendl("lorem ipsum do\0lor sit amet");
	return (0);
}

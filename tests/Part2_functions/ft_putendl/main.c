#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

int		main(int argc, const char *argv[])
{
	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
		ft_putendl("lorem ipsum dolor sit amet");
	else if (atoi(argv[1]) == 2)
		ft_putendl("  lorem\nipsum\rdolor\tsit amet  ");
	else if (atoi(argv[1]) == 3)
		ft_putendl("");
	else if (atoi(argv[1]) == 4)
		ft_putendl("lorem ipsum do\0lor sit amet");
	return (0);
}

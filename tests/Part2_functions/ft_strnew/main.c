#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

int		main(int argc, const char *argv[])
{
	char	*str;
	int		arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		if (!(str = ft_strnew(30)))
			write(1, "NULL", 4);
		else
			write(1, str, 31);
	}
	else if (arg == 2)
	{
		if (!(str = ft_strnew(0)))
			write(1, "NULL", 4);
		else
			write(1, str, 1);
	}
	return (0);
}

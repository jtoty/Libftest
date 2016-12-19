#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

int		main(int argc, const char *argv[])
{
	char	*str;

	str = (char *)malloc(sizeof(*str) * 10);
	if (argc == 1 || !str)
		return (0);
	else if (atoi(argv[1]) == 1)
	{
		ft_strdel(&str);
		if (!str)
			write(1, "NULL", 4);
		else
			write(1, "NOT NULL", 8);
	}
	return (0);
}

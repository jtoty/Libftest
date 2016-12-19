#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../../libft.h"

int		main(int argc, const char *argv[])
{
	char	*str;

	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		str = (char *)malloc(sizeof(*str) * 10);
		if (!str)
			return (0);
		memset(str, 'u', 9);
		str[9] = '\0';
		ft_strclr(str);
		write(1, str, 10);
	}
	return (0);
}

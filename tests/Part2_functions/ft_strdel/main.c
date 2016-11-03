#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

void	ft_print_result(char const *s)
{
	while (*s)
	{
		write(1, &*s, 1);
		s++;
	}
}

int		main(int argc, const char *argv[])
{
	char	*str;

	str = (char *)malloc(sizeof(*str) * 10);
	if (argc == 1 || !str)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		ft_strdel(&str);
		if (!str)
			ft_print_result("NULL");
		else
			ft_print_result("free failed");
	}
	return (0);
}

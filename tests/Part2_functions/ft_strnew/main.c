#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"
#include <limits.h>

void	ft_print_result(char const *s, int n)
{
	int i;
	
	i = 0;
	while (i < n)
	{
		write(1, &s[i], 1);
		i++;
	}
}

int		main(int argc, const char *argv[])
{
	char	*str;

	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		if (!(str = ft_strnew(16)))
			ft_print_result("NULL", 4);
		else
			ft_print_result(str, 17);
	}
	else if (atoi(argv[1]) == 2)
	{
		if (!(str = ft_strnew(ULONG_MAX - 1)))
			ft_print_result("NULL", 4);
	}
	return (0);
}

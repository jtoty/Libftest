#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../../libft.h"

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
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(*dest) * 15)) || argc == 1)
		return (0);
	memset(dest, 0, 15);
	memset(dest, 'f', 9);
	if (atoi(argv[1]) == 1)
	{
		if (dest != ft_strcpy(dest, "lorem"))
			ft_print_result("dest's adress was not returned\n", 30);
		ft_print_result(dest, 15);
	}
	else if (atoi(argv[1]) == 2)
	{
		if (dest != ft_strcpy(dest, "lorem ipsum"))
			ft_print_result("dest's adress was not returned\n", 30);
		ft_print_result(dest, 15);
	}
	else if (atoi(argv[1]) == 3)
	{
		if (dest != ft_strcpy(dest, ""))
			ft_print_result("dest's adress was not returned\n", 30);
		ft_print_result(dest, 15);
	}
	return (0);
}

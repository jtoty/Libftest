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
	memset(dest, 'r', 6);
	if (atoi(argv[1]) == 1)
	{
		dest[8] = 'a';
		if (dest != ft_strncat(dest, "lorem", 2))
			ft_print_result("dest's adress was not returned\n", 31);
		ft_print_result(dest, 15);
	}
	else if (atoi(argv[1]) == 2)
	{
		dest[11] = 'a';
		if (dest != ft_strncat(dest, "lorem", 9))
			ft_print_result("dest's adress was not returned\n", 31);
		ft_print_result(dest, 15);
	}
	else if (atoi(argv[1]) == 3)
	{
		if (dest != ft_strncat(dest, "", 3))
			ft_print_result("dest's adress was not returned\n", 31);
		ft_print_result(dest, 15);
	}
	else if (atoi(argv[1]) == 4)
	{
		if (dest != ft_strncat(dest, "lorem ipsum", 0))
			ft_print_result("dest's adress was not returned\n", 31);
		ft_print_result(dest, 15);
	}
	else if (atoi(argv[1]) == 5)
	{
		dest[0] = '\0';
		dest[10] = 'a';
		if (dest != ft_strncat(dest, "lorem ipsum", 10))
			ft_print_result("dest's adress was not returned\n", 31);
		ft_print_result(dest, 15);
	}
	return (0);
}

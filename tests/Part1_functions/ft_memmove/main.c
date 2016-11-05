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
		write (1, &s[i], 1);
		i++;
	}
}

int		main(int argc, const char *argv[])
{
	char	src[] = "lorem ipsum dolor sit amet";
	char	*dest;

	dest = src + 1;
	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		if (dest != ft_memmove(dest, "consectetur", 5))
			ft_print_result("dest's adress was not returned\n", 30);
		ft_print_result(dest, 22);
	}
	else if (atoi(argv[1]) == 2)
	{
		if (dest != ft_memmove(dest, "con\0sec\0\0te\0tur", 10))
			ft_print_result("dest's adress was not returned\n", 30);
		ft_print_result(dest, 22);
	}
	else if (atoi(argv[1]) == 3)
	{
		if (dest != ft_memmove(dest, src, 8))
			ft_print_result("dest's adress was not returned\n", 30);
		ft_print_result(dest, 22);
	}
	else if (atoi(argv[1]) == 4)
	{
		if (dest != ft_memmove(src, dest,8))
			ft_print_result("dest's adress was not returned\n", 30);
		ft_print_result(dest, 22);
	}
	return (0);
}

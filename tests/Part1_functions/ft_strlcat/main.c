#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"
#include <string.h>

void	ft_print_result(int n)
{
	char c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

void	ft_print_result2(char const *s, int n)
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
		ft_print_result(ft_strlcat(dest, "lorem", 15));
		write(1, "\n", 1);
		ft_print_result2(dest, 15);
	}
	else if (atoi(argv[1]) == 2)
	{
		ft_print_result(ft_strlcat(dest, "", 15));
		write(1, "\n", 1);
		ft_print_result2(dest, 15);
	}
	else if (atoi(argv[1]) == 3)
	{
		dest[0] = '\0';
		ft_print_result(ft_strlcat(dest, "lorem ipsum", 15));
		write(1, "\n", 1);
		ft_print_result2(dest, 15);
	}
	else if (atoi(argv[1]) == 4)
	{
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));
		write(1, "\n", 1);
		ft_print_result2(dest, 15);
	}
	else if (atoi(argv[1]) == 5)
	{
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 0));
		write(1, "\n", 1);
		ft_print_result2(dest, 15);
	}
	else if (atoi(argv[1]) == 6)
	{
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 1));
		write(1, "\n", 1);
		ft_print_result2(dest, 15);
	}
	else if (atoi(argv[1]) == 7)
	{
		memset(dest, 'r', 15);
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
		write(1, "\n", 1);
		ft_print_result2(dest, 15);
	}
	return (0);
}

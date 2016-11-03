#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../../libft.h"

void	ft_print_result(const char *s)
{
	while (*s)
	{
		write(1, &*s, 1);
		s++;
	}
}

int		main(int argc, const char *argv[])
{
	const char *str;

	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		str = ft_memchr("bonjour", 'b', 4);
		if (!str)
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (atoi(argv[1]) == 2)
	{
		str = ft_memchr("bonjour", 'o', 7);
		if (!str)
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (atoi(argv[1]) == 3)
	{
		str = ft_memchr("bonjourno", 'n', 2);
		if (!str)
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (atoi(argv[1]) == 4)
	{
		str = ft_memchr("bonjour", 'j', 6);
		if (!str)
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (atoi(argv[1]) == 5)
	{
		str = ft_memchr("bonjour", 's', 7);
		if (!str)
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	return (0);
}

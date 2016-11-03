#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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
	const char *str;

	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		if (!(str = ft_strstr("lorem ipsum dolor sit amet", "lorem")))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (atoi(argv[1]) == 2)
	{
		if (!(str = ft_strstr("lorem ipsum dolor sit amet", "ipsum")))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (atoi(argv[1]) == 3)
	{
		if (!(str = ft_strstr("lorem ipsum dolor sit lorem ipsum dolor", "ipsum")))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (atoi(argv[1]) == 4)
	{
		if (!(str = ft_strstr("lorem ipsum dolor sit amet", "")))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (atoi(argv[1]) == 5)
	{
		if (!(str = ft_strstr("lorem ipsum dolor sit amet", "ipsumm")))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (atoi(argv[1]) == 6)
	{
		if (!(str = ft_strstr("lorem ipsum dolor sit amet", "dol")))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (atoi(argv[1]) == 7)
	{
		if (!(str = ft_strstr("lorem ipsum dolor sit amet", "consectetur")))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	return (0);
}

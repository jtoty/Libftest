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
	const char *str;

	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "lorem", 15)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (atoi(argv[1]) == 2)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "ipsum", 15)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (atoi(argv[1]) == 3)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit lorem ipsum dolor", "ipsum", 35)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (atoi(argv[1]) == 4)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "", 10)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (atoi(argv[1]) == 5)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (atoi(argv[1]) == 6)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "dol", 30)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (atoi(argv[1]) == 7)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "consectetur", 30)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (atoi(argv[1]) == 8)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "sit", 10)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (atoi(argv[1]) == 9)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 15)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (atoi(argv[1]) == 10)
	{
		if (!(str = ft_strnstr("lorem ipsum dolor sit amet", "dolor", 0)))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	return (0);
}

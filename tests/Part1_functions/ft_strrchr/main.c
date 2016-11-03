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
		if (!(str = ft_strrchr("bonjour", 'b')))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (atoi(argv[1]) == 2)
	{
		if (!(str = ft_strrchr("bonjour", 'o')))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (atoi(argv[1]) == 3)
	{
		if (!(str = ft_strrchr("bonjourno", 'o')))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (atoi(argv[1]) == 4)
	{
		if (!(str = ft_strrchr("bonjour", 'j')))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (atoi(argv[1]) == 5)
	{
		if (!(str = ft_strrchr("bonjour", 's')))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	else if (atoi(argv[1]) == 6)
	{
		if (!(str = ft_strrchr("bonjour", '\0')))
			ft_print_result("NULL");
		else
			ft_print_result(str);
	}
	return (0);
}

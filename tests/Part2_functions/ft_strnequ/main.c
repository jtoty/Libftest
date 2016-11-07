#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

void	ft_print_result(int n)
{
	if (n == 0)
		write(1, "0", 1);
	else
		write(1, "1", 1);
}

int		main(int argc, const char *argv[])
{
	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
		ft_print_result(ft_strnequ("salut", "salut", 6));
	else if (atoi(argv[1]) == 2)
		ft_print_result(ft_strnequ("test", "tests", 6));
	else if (atoi(argv[1]) == 3)
		ft_print_result(ft_strnequ("tests", "test", 6));
	else if (atoi(argv[1]) == 4)
		ft_print_result(ft_strnequ("test", "tEst", 6));
	else if (atoi(argv[1]) == 5)
		ft_print_result(ft_strnequ("", "test", 6));
	else if (atoi(argv[1]) == 6)
		ft_print_result(ft_strnequ("test", "", 6));
	else if (atoi(argv[1]) == 7)
		ft_print_result(ft_strnequ("", "", 6));
	else if (atoi(argv[1]) == 8)
		ft_print_result(ft_strnequ("test", "test", 2));
	else if (atoi(argv[1]) == 9)
		ft_print_result(ft_strnequ("tew", "tez", 2));
	else if (atoi(argv[1]) == 10)
		ft_print_result(ft_strnequ("", "", 0));
	else if (atoi(argv[1]) == 11)
		ft_print_result(ft_strnequ("abcd", "zxyw", 0));
	return (0);
}

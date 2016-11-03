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
		ft_print_result(ft_strequ("salut", "salut"));
	else if (atoi(argv[1]) == 2)
		ft_print_result(ft_strequ("test", "tests"));
	else if (atoi(argv[1]) == 3)
		ft_print_result(ft_strequ("tests", "test"));
	else if (atoi(argv[1]) == 4)
		ft_print_result(ft_strequ("test", "tEst"));
	else if (atoi(argv[1]) == 5)
		ft_print_result(ft_strequ("", "test"));
	else if (atoi(argv[1]) == 6)
		ft_print_result(ft_strequ("test", ""));
	else if (atoi(argv[1]) == 7)
		ft_print_result(ft_strequ("", ""));
	return (0);
}

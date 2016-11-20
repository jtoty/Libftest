#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

void	ft_print_result(int n)
{
	if (n > 0)
		write(1, "1", 1);
	else if (n < 0)
		write(1, "-1", 2);
	else
		write(1, "0", 1);
}

int		main(int argc, const char *argv[])
{
	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
		ft_print_result(ft_strcasecmp("salut", "salut"));
	else if (atoi(argv[1]) == 2)
		ft_print_result(ft_strcasecmp("test", "testss"));
	else if (atoi(argv[1]) == 3)
		ft_print_result(ft_strcasecmp("testss", "test"));
	else if (atoi(argv[1]) == 4)
		ft_print_result(ft_strcasecmp("test", "tEst"));
	else if (atoi(argv[1]) == 5)
		ft_print_result(ft_strcasecmp("", "test"));
	else if (atoi(argv[1]) == 6)
		ft_print_result(ft_strcasecmp("test", ""));
	else if (atoi(argv[1]) == 7)
		ft_print_result(ft_strcasecmp("test\200", "test\0"));
	return (0);
}

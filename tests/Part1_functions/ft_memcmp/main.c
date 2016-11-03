#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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
		ft_print_result(ft_memcmp("salut", "salut", 5));
	else if (atoi(argv[1]) == 2)
		ft_print_result(ft_memcmp("test", "testss", 8));
	else if (atoi(argv[1]) == 3)
		ft_print_result(ft_memcmp("testss", "test", 8));
	else if (atoi(argv[1]) == 4)
		ft_print_result(ft_memcmp("test", "tEst", 5));
	else if (atoi(argv[1]) == 5)
		ft_print_result(ft_memcmp("", "test", 5));
	else if (atoi(argv[1]) == 6)
		ft_print_result(ft_memcmp("test", "", 5));
	else if (atoi(argv[1]) == 7)
		ft_print_result(ft_memcmp("abcdefghij", "abcdefgxyz", 7));
	else if (atoi(argv[1]) == 8)
		ft_print_result(ft_memcmp("abcdefgh", "abcdwxyz", 6));
	else if (atoi(argv[1]) == 9)
		ft_print_result(ft_memcmp("abcdefgh", "abcdefgxyz", 0));
	return (0);
}

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
		ft_print_result(ft_strncmp("salut", "salut", 5));
	else if (atoi(argv[1]) == 2)
		ft_print_result(ft_strncmp("test", "testss", 7));
	else if (atoi(argv[1]) == 3)
		ft_print_result(ft_strncmp("testss", "test", 7));
	else if (atoi(argv[1]) == 4)
		ft_print_result(ft_strncmp("test", "tEst", 4));
	else if (atoi(argv[1]) == 5)
		ft_print_result(ft_strncmp("", "test", 4));
	else if (atoi(argv[1]) == 6)
		ft_print_result(ft_strncmp("test", "", 4));
	else if (atoi(argv[1]) == 7)
		ft_print_result(ft_strncmp("abcdefghij", "abcdefgxyz", 3));
	else if (atoi(argv[1]) == 8)
		ft_print_result(ft_strncmp("abcdefgh", "abcdwxyz", 4));
	else if (atoi(argv[1]) == 9)
		ft_print_result(ft_strncmp("zyxbcdefgh", "abcdwxyz", 0));
	else if (atoi(argv[1]) == 10)
		ft_print_result(ft_strncmp("abcdefgh", "", 0));
	else if (atoi(argv[1]) == 11)
		ft_print_result(ft_strncmp("test\200", "test\0", 6));
	return (0);
}

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
	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
	ft_print_result(ft_itoa(0));
	else if (atoi(argv[1]) == 2)
		ft_print_result(ft_itoa(5));
	else if (atoi(argv[1]) == 3)
		ft_print_result(ft_itoa(-5));
	else if (atoi(argv[1]) == 4)
		ft_print_result(ft_itoa(8124));
	else if (atoi(argv[1]) == 5)
		ft_print_result(ft_itoa(-9874));
	else if (atoi(argv[1]) == 6)
		ft_print_result(ft_itoa(543000));
	else if (atoi(argv[1]) == 7)
		ft_print_result(ft_itoa(-2147483648LL));
	else if (atoi(argv[1]) == 8)
		ft_print_result(ft_itoa(2147483647));
	return (0);
}

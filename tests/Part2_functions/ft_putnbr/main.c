#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

int		main(int argc, const char *argv[])
{
	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
		ft_putnbr(0);
	else if (atoi(argv[1]) == 2)
		ft_putnbr(5);
	else if (atoi(argv[1]) == 3)
		ft_putnbr(-5);
	else if (atoi(argv[1]) == 4)
		ft_putnbr(42);
	else if (atoi(argv[1]) == 5)
		ft_putnbr(-57);
	else if (atoi(argv[1]) == 6)
		ft_putnbr(164189);
	else if (atoi(argv[1]) == 7)
		ft_putnbr(-987441);
	else if (atoi(argv[1]) == 8)
		ft_putnbr(2147483647);
	else if (atoi(argv[1]) == 9)
		ft_putnbr(-2147483648LL);
	return (0);
}

#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

void	ft_print_result2(char c)
{
	write(1, &c, 1);
}

void	ft_print_result(int n)
{
	if (n >= 0)
	{
		if (n >= 10)
			ft_print_result(n / 10);
		ft_print_result2(n % 10 + '0');
	}
	else
	{
		ft_print_result2('-');
		if (n <= -10)
			ft_print_result(n / -10);
		ft_print_result2(n % -10 * -1 + '0');
	}
}

int main(int argc, const char *argv[])
{
	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
		ft_print_result(ft_atoi("0"));
	else if (atoi(argv[1]) == 2)
		ft_print_result(ft_atoi("546"));
	else if (atoi(argv[1]) == 3)
		ft_print_result(ft_atoi("-4886"));
	else if (atoi(argv[1]) == 4)
		ft_print_result(ft_atoi("+548"));
	else if (atoi(argv[1]) == 5)
		ft_print_result(ft_atoi("054854"));
	else if (atoi(argv[1]) == 6)
		ft_print_result(ft_atoi("000074"));
	else if (atoi(argv[1]) == 7)
		ft_print_result(ft_atoi("+-54"));
	else if (atoi(argv[1]) == 8)
		ft_print_result(ft_atoi("-+48"));
	else if (atoi(argv[1]) == 9)
		ft_print_result(ft_atoi("--47"));
	else if (atoi(argv[1]) == 10)
		ft_print_result(ft_atoi("++47"));
	else if (atoi(argv[1]) == 11)
		ft_print_result(ft_atoi("+47+5"));
	else if (atoi(argv[1]) == 12)
		ft_print_result(ft_atoi("-47-5"));
	else if (atoi(argv[1]) == 13)
		ft_print_result(ft_atoi("  475 4"));
	else if (atoi(argv[1]) == 14)
		ft_print_result(ft_atoi("\t\n\r\v\f  469 \n"));
	else if (atoi(argv[1]) == 15)
		ft_print_result(ft_atoi("-2147483648"));
	else if (atoi(argv[1]) == 16)
		ft_print_result(ft_atoi("2147483647"));
	else if (atoi(argv[1]) == 17)
		ft_print_result(ft_atoi("\t\n\r\v\fd469 \n"));
	else if (atoi(argv[1]) == 18)
		ft_print_result(ft_atoi("\n\n\n  46\b9 \nd"));
	return (0);
}

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
	void	*mem;
	void	*membis;

	if (!(mem = malloc(sizeof(*mem) * 30)) || argc == 1)
		return (0);
	memset(mem, 'j', 29);
	((char*)mem)[29] = '\0';
	membis = mem;
	if (atoi(argv[1]) == 1)
	{
		if (!(mem = ft_memccpy(mem, "zyxwvutsrqponmlkjihgfedcba", 'r', 20)))
			ft_print_result("NULL");
		else
		{
			ft_print_result(mem);
			write(1, "\n", 1);
			ft_print_result(membis);
		}
	}
	else if (atoi(argv[1]) == 2)
	{
		if (!(mem = ft_memccpy(mem, "zyxwvutsrqponmlkjihgfedcba", 'r', 3)))
			ft_print_result("NULL");
		else
		{
			ft_print_result(mem);
			write(1, "\n", 1);
			ft_print_result(membis);
		}
	}
	else if (atoi(argv[1]) == 3)
	{
		if (!(mem = ft_memccpy(mem, "zyxwvutsrqponmlkjihgfedcba", 'a', 26)))
			ft_print_result("NULL");
		else
		{
			ft_print_result(mem);
			write(1, "\n", 1);
			ft_print_result(membis);
		}
	}
	else if (atoi(argv[1]) == 4)
	{
		if (!(mem = ft_memccpy(mem, "zyxwvuzyxwvu", 'x', 20)))
			ft_print_result("NULL");
		else
		{
			ft_print_result(mem);
			write(1, "\n", 1);
			ft_print_result(membis);
		}
	}
	return (0);
}

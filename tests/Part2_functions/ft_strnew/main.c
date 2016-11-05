#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"
#include <malloc/malloc.h>

void	ft_print_result(char const *s, int n)
{
	int i;
	
	i = 0;
	while (i < n)
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_print_result2(int n)
{
	char c;

	if (n >= 10)
		ft_print_result2(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

int		main(int argc, const char *argv[])
{
	char	*str;

	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		if (!(str = ft_strnew(16)))
			ft_print_result("NULL", 4);
		else
		{
			ft_print_result2(malloc_size(str));
			ft_print_result(str, 17);
		}
	}
	return (0);
}

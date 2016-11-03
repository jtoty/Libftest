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

void	iter(unsigned int i, char *c)
{
	c[i] = 'z';
}

int		main(int argc, const char *argv[])
{
	char	*str;

	str = (char *)malloc(sizeof(*str) * 10);
	if (argc == 1 || !str)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		memset(str, 'w', 9);
		str[9] = '\0';
		ft_striteri(str, &iter);
		ft_print_result(str);
	}
	return (0);
}

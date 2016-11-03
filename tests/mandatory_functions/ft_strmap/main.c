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

char	map(char c)
{
	c = 'y';
	return (c);
}

int		main(int argc, const char *argv[])
{
	char	*str;
	char	*strmap;

	str = (char *)malloc(sizeof(*str) * 10);
	if (argc == 1 || !str)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		memset(str, 'd', 9);
		str[9] = '\0';
		strmap = ft_strmap(str, &map);
		ft_print_result(strmap);
		if (strmap == str)
			ft_print_result("\nA new string was not returned");
	}
	return (0);
}

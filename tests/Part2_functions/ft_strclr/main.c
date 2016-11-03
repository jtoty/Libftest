#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../../libft.h"

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

int		main(int argc, const char *argv[])
{
	char	*str;

	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		str = (char *)malloc(sizeof(*str) * 10);
		if (!str)
			return (0);
		memset(str, 'u', 9);
		str[9] = '\0';
		ft_strclr(str);
		ft_print_result(str, 10);
	}
	return (0);
}

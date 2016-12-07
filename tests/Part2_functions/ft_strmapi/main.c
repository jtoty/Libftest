#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void	ft_print_result(char const *s)
{
	while (*s)
	{
		write(1, &*s, 1);
		s++;
	}
}

void ft_print_result2(int n)
{
	char c;

	if (n >= 10)
		ft_print_result2(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

char	mapi(unsigned int i, char c)
{
	ft_print_result2(i);
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

int		main(int argc, const char *argv[])
{
	char	*str;
	char	*strmapi;

	str = (char *)malloc(sizeof(*str) * 12);
	if (argc == 1 || !str)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		strcpy(str, "LoReM iPsUm");
		strmapi = ft_strmapi(str, &mapi);
		write(1, "\n", 1);
		ft_print_result(strmapi);
		if (strmapi == str)
			ft_print_result("\nA new string was not returned");
		if (strmapi[11] != '\0')
			ft_print_result("\nString is not null terminated");
	}
	return (0);
}

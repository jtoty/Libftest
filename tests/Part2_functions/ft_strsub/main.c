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
	char str[] = "lorem ipsum dolor sit amet";
	char *strsub;

	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		if (!(strsub = ft_strsub(str, 0, 10)))
			ft_print_result("NULL");
		else
			ft_print_result(strsub);
		if (str == strsub)
			ft_print_result("\nA new string was not returned");
	}
	else if (atoi(argv[1]) == 2)
	{
		if (!(strsub = ft_strsub(str, 7, 10)))
			ft_print_result("NULL");
		else
			ft_print_result(strsub);
		if (str == strsub)
			ft_print_result("\nA new string was not returned");
	}
	else if (atoi(argv[1]) == 3)
	{
		if (!(strsub = ft_strsub(str, 7, 0)))
			ft_print_result("NULL");
		else
			ft_print_result(strsub);
		if (str == strsub)
			ft_print_result("\nA new string was not returned");
	}
	return (0);
}

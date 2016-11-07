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
	char	*strtrim;

	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		char s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
		if (!(strtrim = ft_strtrim(s1)))
			ft_print_result("NULL");
		else
			ft_print_result(strtrim);
		if (strtrim == s1)
			ft_print_result("\nA new string was not returned");
	}
	else if (atoi(argv[1]) == 2)
	{
		char s1[] = "lorem ipsum dolor sit amet \n \t ";
		if (!(strtrim = ft_strtrim(s1)))
			ft_print_result("NULL");
		else
			ft_print_result(strtrim);
		if (strtrim == s1)
			ft_print_result("\nA new string was not returned");
	}
	else if (atoi(argv[1]) == 3)
	{
		char s1[] = " \n \t lorem ipsum dolor sit amet";
		if (!(strtrim = ft_strtrim(s1)))
			ft_print_result("NULL");
		else
			ft_print_result(strtrim);
		if (strtrim == s1)
			ft_print_result("\nA new string was not returned");
	}
	else if (atoi(argv[1]) == 4)
	{
		char s1[] = "  \n  \t  lorem \n ipsum \t dolor \n sit \t amet  \t \n ";
		if (!(strtrim = ft_strtrim(s1)))
			ft_print_result("NULL");
		else
			ft_print_result(strtrim);
		if (strtrim == s1)
			ft_print_result("\nA new string was not returned");
	}
	else if (atoi(argv[1]) == 5)
	{
		char s1[] = "          ";
		if (!(strtrim = ft_strtrim(s1)))
			ft_print_result("NULL");
		else
			ft_print_result(strtrim);
		if (strtrim == s1)
			ft_print_result("\nA new string was not returned");
	}
	return (0);
}

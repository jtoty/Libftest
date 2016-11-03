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
	char **tabstr;
	int i;

	if (argc == 1)
		return (0);
	i = 0;
	if (atoi(argv[1]) == 1)
	{
		if (!(tabstr = ft_strsplit("lorem ipsum dolor sit amet", ' ')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != '\0')
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	else if (atoi(argv[1]) == 2)
	{
		if (!(tabstr = ft_strsplit("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != '\0')
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	else if (atoi(argv[1]) == 3)
	{
		if (!(tabstr = ft_strsplit("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", 'i')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != '\0')
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	else if (atoi(argv[1]) == 4)
	{
		if (!(tabstr = ft_strsplit("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != '\0')
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	return (0);
}

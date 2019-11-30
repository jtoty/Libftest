#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static void		ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void		check_strcasestr(const char *haystack, const char *needle)
{
	const char	*str;

	if (!(str = ft_strcasestr(haystack, needle)))
		ft_print_result("NULL");
	else
		ft_print_result(str);
}

int				main(int argc, const char *argv[])
{
	int			arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		check_strcasestr("lorEm ipsum dolor sit amet", "loRem");
	else if (arg == 2)
		check_strcasestr("lorem iPsum dolor sit amet", "iPSum");
	else if (arg == 3)
		check_strcasestr("lorem iPSum dolor sit lorem ipsum dolor", "ipsum");
	else if (arg == 4)
		check_strcasestr("lorem ipsum dolor sit amet", "");
	else if (arg == 5)
		check_strcasestr("lorem ipsum dolor sit amet", "ipSUmm");
	else if (arg == 6)
		check_strcasestr("lorem ipsum dolor sit amet", "dOl");
	else if (arg == 7)
		check_strcasestr("lorem ipsum dolor sit amet", "consECtetur");
	return (0);
}

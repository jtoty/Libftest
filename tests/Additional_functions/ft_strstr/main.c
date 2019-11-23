/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:08:47 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:48:51 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

static void		ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void		check_strstr(char *haystack, char *needle)
{
	const char	*str;

	if (!(str = ft_strstr(haystack, needle)))
		ft_print_result("NULL");
	else
		ft_print_result(str);
}

int				main(int argc, const char *argv[])
{
	int			arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		check_strstr("lorem ipsum dolor sit amet", "lorem");
	else if (arg == 2)
		check_strstr("lorem ipsum dolor sit amet", "ipsum");
	else if (arg == 3)
		check_strstr("lorem ipsum dolor sit lorem ipsum dolor", "ipsum");
	else if (arg == 4)
		check_strstr("lorem ipsum dolor sit amet", "");
	else if (arg == 5)
		check_strstr("lorem ipsum dolor sit amet", "ipsumm");
	else if (arg == 6)
		check_strstr("lorem ipsum dolor sit amet", "dol");
	else if (arg == 7)
		check_strstr("lorem ipsum dolor sit amet", "consectetur");
	return (0);
}

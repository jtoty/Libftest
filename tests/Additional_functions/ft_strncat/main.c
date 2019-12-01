/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:06:58 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:45:04 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

static void		check_strncat(char *dest, char *src, int n, int len)
{
	if (dest != ft_strncat(dest, src, n))
		write(1, "dest's adress was not returned\n", 31);
	write(1, dest, len);
}

int		main(int argc, const char *argv[])
{
	char	*dest;
	int		arg;
	int		len;

	alarm(5);
	len = 15;
	if (!(dest = (char *)malloc(sizeof(*dest) * len)) || argc == 1)
		return (0);
	memset(dest, 0, len);
	memset(dest, 'r', 6);
	if ((arg = atoi(argv[1])) == 1)
	{
		dest[8] = 'a';
		check_strncat(dest, "lorem", 2, len);
	}
	else if (arg == 2)
	{
		dest[11] = 'a';
		check_strncat(dest, "lorem", 9, len);
	}
	else if (arg == 3)
		check_strncat(dest, "", 3, len);
	else if (arg == 4)
		check_strncat(dest, "lorem ipsum", 0, len);
	else if (arg == 5)
	{
		dest[0] = '\0';
		dest[10] = 'a';
		check_strncat(dest, "lorem ipsum", 10, len);
	}
	free(dest);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:03:07 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:43:38 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

static void		check_strcat(char *dest, char *src, int len)
{
	if (dest != ft_strcat(dest, src))
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
		dest[11] = 'a';
		check_strcat(dest, "lorem", 15);
	}
	else if (arg == 2)
		check_strcat(dest, "", 15);
	else if (arg == 3)
	{
		dest[0] = '\0';
		dest[11] = 'a';
		check_strcat(dest, "lorem ipsum", 15);
	}
	free(dest);
	return (0);
}

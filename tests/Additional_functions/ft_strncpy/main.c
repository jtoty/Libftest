/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:07:53 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:48:21 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

static void		check_strncpy(char *dest, char *src, int n, int len)
{
	if (dest != ft_strncpy(dest, src, n))
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
	memset(dest, 0, 15);
	if ((arg = atoi(argv[1])) == 1)
	{
		memset(dest, 's', 13);
		check_strncpy(dest, "lorem", 6, len);
	}
	else if (arg == 2)
	{
		memset(dest, 's', 13);
		check_strncpy(dest, "lorem", 8, len);
	}
	else if (arg == 3)
	{
		memset(dest, 's', 13);
		check_strncpy(dest, "", 3, len);
	}
	else if (arg == 4)
	{
		memset(dest, 's', 13);
		check_strncpy(dest, "lorem ipsum", 3, len);
	}
	else if (arg == 5)
	{
		memset(dest, 's', 13);
		check_strncpy(dest, "lorem ipsum", 0, len);
	}
	else if (arg == 6)
	{
		memset(dest, 's', 5);
		check_strncpy(dest, "lorem ipsum", 10, len);
	}
	free(dest);
	return (0);
}

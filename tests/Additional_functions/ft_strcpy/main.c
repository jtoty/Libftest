/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:04:46 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:44:13 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

static void		check_strcpy(char *dest, char *src, int len)
{
	if (dest != ft_strcpy(dest, src))
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
	memset(dest, 'f', 9);
	if ((arg = atoi(argv[1])) == 1)
		check_strcpy(dest, "lorem", len);
	else if (arg == 2)
		check_strcpy(dest, "lorem ipsum", len);
	else if (arg == 3)
		check_strcpy(dest, "", len);
	free(dest);
	return (0);
}

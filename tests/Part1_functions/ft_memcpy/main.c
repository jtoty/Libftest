/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:02:06 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:43:04 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

static void		check_memcpy(void *dest, void *src, int n)
{
	if (dest != ft_memcpy(dest, src, n))
		write(1, "dest's adress was not returned\n", 31);
	write(1, dest, 30);
	free(dest);
}

int				main(int argc, const char *argv[])
{
	void	*mem;
	int		arg;

	alarm(5);
	if (!(mem = malloc(sizeof(*mem) * 30)) || argc == 1)
		return (0);
	memset(mem, 'j', 30);
	if ((arg = atoi(argv[1])) == 1)
		check_memcpy(mem, "zyxwvutsrqponmlkjihgfedcba", 14);
	else if (arg == 2)
		check_memcpy(mem, "zyxwvutst", 0);
	else if (arg == 3)
		check_memcpy(mem, "zy\0xw\0vu\0\0tsr", 11);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:45:24 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:50:43 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static void		check_putchar(int start, int end)
{
	while (start <= end)
	{
		ft_putchar(start);
		start++;
	}
}

int				main(int argc, const char *argv[])
{
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		check_putchar(0, 47);
	else if (arg == 2)
		check_putchar('0', '9');
	else if (arg == 3)
		check_putchar(58, 64);
	else if (arg == 4)
		check_putchar('A', 'Z');
	else if (arg == 5)
		check_putchar(91, 96);
	else if (arg == 6)
		check_putchar('a', 'z');
	else if (arg == 7)
		check_putchar(123, 127);
	return (0);
}

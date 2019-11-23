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

static void		check_putchar_fd(int start, int end, int fd)
{
	while (start <= end)
	{
		ft_putchar_fd(start, fd);
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
		check_putchar_fd(0, 47, 2);
	else if (arg == 2)
		check_putchar_fd('0', '9', 1);
	else if (arg == 3)
		check_putchar_fd(58, 64, 2);
	else if (arg == 4)
		check_putchar_fd('A', 'Z', 1);
	else if (arg == 5)
		check_putchar_fd(91, 96, 2);
	else if (arg == 6)
		check_putchar_fd('a', 'z', 1);
	else if (arg == 7)
		check_putchar_fd(123, 127, 2);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:25:33 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:58:57 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static void		ft_print_result(int n)
{
	if (n)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

static void		check_isspace(int start, int end)
{
	while (start <= end)
	{
		ft_print_result(ft_isspace(start));
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
		check_isspace(0, 47);
	else if (arg == 2)
		check_isspace('0', '9');
	else if (arg == 3)
		check_isspace(58, 64);
	else if (arg == 4)
		check_isspace('A', 'Z');
	else if (arg == 5)
		check_isspace(91, 96);
	else if (arg == 6)
		check_isspace('a', 'z');
	else if (arg == 7)
		check_isspace(123, 127);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:59:49 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:38:50 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "libft.h"

static void		ft_print_result(int n)
{
	if (n)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

static void		check_isalpha(int start, int end)
{
	while (start <= end)
	{
		ft_print_result(ft_isalpha(start));
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
		check_isalpha(0, 47);
	else if (arg == 2)
		check_isalpha('0', '9');
	else if (arg == 3)
		check_isalpha(58, 64);
	else if (arg == 4)
		check_isalpha('A', 'Z');
	else if (arg == 5)
		check_isalpha(91, 96);
	else if (arg == 6)
		check_isalpha('a', 'z');
	else if (arg == 7)
		check_isalpha(123, 127);
	return (0);
}

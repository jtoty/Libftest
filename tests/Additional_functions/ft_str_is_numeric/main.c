/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:27:11 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 16:00:16 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static void	ft_print_result(int n)
{
	if (n)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

static void		check_str_is_numeric(int start, int end)
{
	char	str[] = "0123456789012345678901";

	while (start <= end)
	{
		str[0] = start;
		ft_print_result(ft_str_is_numeric(str));
		start++;
	}
}

int			main(int argc, const char *argv[])
{
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		check_str_is_numeric(0, 47);
	else if (arg == 2)
		check_str_is_numeric('0', '9');
	else if (arg == 3)
		check_str_is_numeric(58, 64);
	else if (arg == 4)
		check_str_is_numeric('A', 'Z');
	else if (arg == 5)
		check_str_is_numeric(91, 96);
	else if (arg == 6)
		check_str_is_numeric('a', 'z');
	else if (arg == 7)
		check_str_is_numeric(123, 127);
	return (0);
}

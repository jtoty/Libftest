/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:26:21 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:59:43 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static void		ft_print_result(char *s)
{
	int		len;

	if (!s)
		write(1, "NULL", 4);
	else
	{
		len = 0;
		while (s[len])
		{
			if (s[len] >= 'a' && s[len] <= 'z')
				s[len] -= 32;
			len++;
		}
		write(1, s, len);
		free(s);
	}
	write(1, "\n", 1);
}

static void		check_itoa_base(int arg)
{
	int		base;

	base = arg + 1;
	ft_print_result(ft_itoa_base(0, base));
	ft_print_result(ft_itoa_base(arg, base));
	ft_print_result(ft_itoa_base(-arg, base));
	ft_print_result(ft_itoa_base(arg + 1, base));
	ft_print_result(ft_itoa_base(-(arg + 1), base));
	ft_print_result(ft_itoa_base(8124, base));
	ft_print_result(ft_itoa_base(-9874, base));
	ft_print_result(ft_itoa_base(543000, base));
	ft_print_result(ft_itoa_base(-2147483648LL, base));
	ft_print_result(ft_itoa_base(2147483647, base));
}

int				main(int argc, const char *argv[])
{
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	arg = atoi(argv[1]);
	if (arg > 0)
		check_itoa_base(arg);
	return (0);
}

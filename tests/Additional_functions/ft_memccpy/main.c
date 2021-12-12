/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:01:23 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:39:32 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

static void		ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void		check_memccpy(void *dest, void *src, int c, int n)
{
	void	*membis;

	membis = dest;
	if (!(dest = ft_memccpy(dest, src, c, n)))
	{
		ft_print_result("NULL");
		write(1, "\n", 1);
		ft_print_result(membis);
	}
	else
	{
		ft_print_result(dest);
		write(1, "\n", 1);
		ft_print_result(membis);
	}
	free(membis);
}

int				main(int argc, const char *argv[])
{
	void	*mem;
	int		arg;

	alarm(5);
	if (!(mem = malloc(sizeof(*mem) * 30)) || argc == 1)
		return (0);
	memset(mem, 'j', 29);
	((char*)mem)[29] = '\0';
	if ((arg = atoi(argv[1])) == 1)
		check_memccpy(mem, "zyxwvutsrqponmlkjihgfedcba", 'r', 20);
	else if (arg == 2)
		check_memccpy(mem, "zyxwvutsrqponmlkjihgfedcba", 'r', 3);
	else if (arg == 3)
		check_memccpy(mem, "zyxwvutsrqponmlkjihgfedcba", 'a', 26);
	else if (arg == 4)
		check_memccpy(mem, "zyxwvuzyxwvu", 'x', 20);
	return (0);
}

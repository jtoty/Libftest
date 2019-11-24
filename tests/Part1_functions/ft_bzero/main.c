/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 11:58:52 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:38:29 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

static void		check_bzero(void *mem, int c, int len, int n_bzero)
{
	memset(mem, c, len);
	ft_bzero(mem, n_bzero);
	write(1, mem, len);
}

int				main(int argc, const char *argv[])
{
	void	*mem;
	int		len;
	int		arg;

	alarm(5);
	len = 5;
	if (argc == 1 || !(mem = malloc(sizeof(*mem) * len)))
		return (0);
	if ((arg = atoi(argv[1])) == 1)
		check_bzero(mem, 'e', len, 5);
	else if (arg == 2)
		check_bzero(mem, 'e', len, 0);
	free(mem);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:34:47 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:54:12 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static void		check_strnew(int len)
{
	char	*str;

	if (!(str = ft_strnew(len)))
		write(1, "NULL", 4);
	else
		write(1, str, len + 1);
	free(str);
}

int				main(int argc, const char *argv[])
{
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		check_strnew(30);
	else if (arg == 2)
		check_strnew(0);
	return (0);
}

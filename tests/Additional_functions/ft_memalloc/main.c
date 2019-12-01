/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:23:17 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:50:25 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

int		main(int argc, const char *argv[])
{
	char	*str;

	alarm(5);
	if (argc == 1)
		return (0);
	else if (atoi(argv[1]) == 1)
	{
		str = (char *)ft_memalloc(30);
		if (!str)
			write(1, "NULL", 4);
		else
			write(1, str, 30);
		free(str);
	}
	return (0);
}

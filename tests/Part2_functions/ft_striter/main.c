/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:33:23 by jtoty             #+#    #+#             */
/*   Updated: 2017/02/28 12:33:31 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../../../libft.h"

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

void	iter(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
	else if (*c >= 'A' && *c <= 'Z')
		*c = *c + 32;
}

int		main(int argc, const char *argv[])
{
	char	*str;

	ualarm(5000000, 0);
	str = (char *)malloc(sizeof(*str) * 12);
	if (argc == 1 || !str)
		return (0);
	else if (atoi(argv[1]) == 1)
	{
		strcpy(str, "LoReM iPsUm");
		ft_striter(str, &iter);
		ft_print_result(str);
	}
	return (0);
}

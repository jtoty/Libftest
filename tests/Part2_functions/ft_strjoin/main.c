/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:33:59 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:53:29 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static void			ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void			check_strjoin(char *s1, char *s2)
{
	char	*strjoin;

	if (!(strjoin = ft_strjoin(s1, s2)))
		ft_print_result("NULL");
	else
		ft_print_result(strjoin);
	if (strjoin == s1 || strjoin == s2)
		ft_print_result("\nA new string was not returned");
	else
		free(strjoin);
}

int					main(int argc, const char *argv[])
{
	char	s1[] = "lorem ipsum";
	char	s2[] = "dolor sit amet";
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		check_strjoin(s1, s2);
	}
	else if (arg == 2)
	{
		s1[0] = '\0';
		check_strjoin(s1, s2);
	}
	else if (arg == 3)
	{
		s2[0] = '\0';
		check_strjoin(s1, s2);
	}
	else if (arg == 4)
	{
		s1[0] = '\0';
		s2[0] = '\0';
		check_strjoin(s1, s2);
	}
	return (0);
}

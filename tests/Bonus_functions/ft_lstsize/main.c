/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:16:05 by jtoty             #+#    #+#             */
/*   Updated: 2019/11/20 15:55:49 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include <string.h>

static void		ft_print_result2(char c)
{
	write(1, &c, 1);
}

static void		ft_print_result(int n)
{
	if (n >= 0)
	{
		if (n >= 10)
			ft_print_result(n / 10);
		ft_print_result2(n % 10 + '0');
	}
}

static t_list	*get_lst_new_elem(void const *content, size_t content_size)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	if (!content)
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	else
	{
		if (!(elem->content = malloc(sizeof(*(elem->content)) * content_size)))
		{
			free(elem);
			return (NULL);
		}
		elem->content = memcpy(elem->content, content, content_size);
		elem->content_size = content_size;
	}
	elem->next = NULL;
	return (elem);
}

int 			main(int argc, const char *argv[])
{
	int			arg;
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	char		str [] = "lorem";
	char		str2 [] = "ipsum";
	char		str3 [] = "dolor";
	char		str4 [] = "sit";

	elem = get_lst_new_elem(str, sizeof(str));
	elem2 = get_lst_new_elem(str2, sizeof(str2));
	elem3 = get_lst_new_elem(str3, sizeof(str3));
	elem4 = get_lst_new_elem(str4, sizeof(str4));
	alarm(5);
	if (argc == 1 || !elem || !elem2 || !elem3 || !elem4)
		return (0);
	elem->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	if ((arg = atoi(argv[1])) == 1)
	{
		ft_print_result(ft_lstsize(elem));
	}
	else if (arg == 2)
	{
		ft_print_result(ft_lstsize(elem4));
	}
	else if (arg == 3)
	{
		ft_print_result(ft_lstsize(NULL));
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:16:21 by jtoty             #+#    #+#             */
/*   Updated: 2017/03/09 15:56:01 by jtoty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <unistd.h>
#include <string.h>

// static void			ft_print_result(t_list *elem)
// {
// 	int		len;
//
// 	len = 0;
// 	while (((char *)elem->content)[len])
// 		len++;
// 	write(1, elem->content, len);
// 	write(1, "\n", 1);
// }

static t_list		*get_lst_new_elem(void *content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

static void			free_memory_and_return(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

static void			free_memory_lst_and_return(t_list *elem)
{
	t_list		*tmp;

	while (elem)
	{
		tmp = elem->next;
		free(elem);
		elem = tmp;
	}
}

static char			**get_content_lst(int size)
{
	char	**tab;
	int		i;
	char	str [] = "abcdef";

	if (!(tab = (char **)malloc(sizeof(*tab) * size + 1)))
		return (0);
	tab[size] = NULL;
	i = 0;
	while (i < size)
	{
		str[0] += i % 25;
		if (!(tab[i] = strdup(str)))
		{
			free_memory_and_return(tab, i - 1);
			return (NULL);
		}
		i++;
	}
	return (tab);
}

static t_list		*get_elem_lst(t_list *begin, char **tab, int i)
{
	t_list		*elem;

	if (!(elem = get_lst_new_elem(tab[i])))
	{
		free_memory_lst_and_return(begin);
		free_memory_and_return(tab, 4);
		return (NULL);
	}
	return (elem);
}
#include <stdio.h>

static void			ft_delelem(t_list *elem)
{
	if (elem)
		free(elem->content);
}

static void		*ft_mapelem(char *content)
{
	int		i;

	i = 0;

	while (content[i])
	{
		content[i] = 'y';
		i++;
	}
	return (content);
}
int				 	main(int argc, const char *argv[])
{
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	t_list		*tmp;;
	t_list		*list;
	char		**tab;

	if (argc == 1 || (!(tab = get_content_lst(4))))
		return (0);
	elem = NULL;
	if (!(elem = get_elem_lst(elem, tab, 0)))
		return (0);
	if (!(elem2 = get_elem_lst(elem, tab, 1)))
		return (0);
	elem->next = elem2;
	if (!(elem3 = get_elem_lst(elem, tab, 2)))
		return (0);
	elem2->next = elem3;
	if (!(elem4 = get_elem_lst(elem, tab, 3)))
		return (0);
	elem3->next = elem4;
	alarm(5);
	if (atoi(argv[1]) == 1)
	{
		printf("elem content = %s\n", elem->content);
		printf("elem content = %s\n", elem2->content);
		printf("elem content = %s\n", elem3->content);
		printf("elem content = %s\n\n", elem4->content);
		if (!(list = ft_lstmap(elem, (void *)&ft_mapelem, (void *)&ft_delelem)))
		{
			free(tab[3]);
			free(tab);
			free_memory_and_return(tab, 4);
			free_memory_lst_and_return(elem);
			return (0);
		}
		if (list == elem)
			write(1, "A new list is not returned\n", 27);
		tmp = list;
		printf("tmp = %s elem = %s\n", tmp->content, elem->content);

		while (tmp)
		{
			printf("tmp = %s\n", tmp->content);
			// ft_print_result();
			tmp = tmp->next;
		}
		free_memory_lst_and_return(list);
	}
	free_memory_and_return(tab, 4);
	free_memory_lst_and_return(elem);
	return (0);
}

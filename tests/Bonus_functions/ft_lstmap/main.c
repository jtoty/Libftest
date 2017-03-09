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
#include "../../../libft.h"
#include <unistd.h>
#include <string.h>

void	ft_print_result(t_list *elem)
{
	int		len;

	len = 0;
	while (((char *)elem->content)[len])
		len++;
	write(1, elem->content, len);
	write(1, "\n", 1);
}

t_list	*ft_map(t_list *elem)
{
	int		i;
	t_list	*new_elem;

	new_elem = ft_lstnew(elem->content, elem->content_size);
	if (!new_elem)
		return (0);
	i = 0;
	while (((char *)new_elem->content)[i])
	{
		((char *)new_elem->content)[i] = 'y';
		i++;
	}
	return (new_elem);
}


t_list	*ft_lstnew(void const *content, size_t content_size)
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
			return (NULL);
		elem->content = memcpy(elem->content, content, content_size);
		elem->content_size = content_size;
	}
	elem->next = NULL;
	return (elem);
}

int main(int argc, const char *argv[])
{
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	t_list		*list;
	char		str [] = "lorem";
	char		str2 [] = "ipsum";
	char		str3 [] = "dolor";
	char		str4 [] = "sit";

	elem = ft_lstnew(str, sizeof(str));
	elem2 = ft_lstnew(str2, sizeof(str2));
	elem3 = ft_lstnew(str3, sizeof(str3));
	elem4 = ft_lstnew(str4, sizeof(str4));
	alarm(5);
	if (argc == 1 || !elem || !elem2 || !elem3 || !elem4)
		return (0);
	elem->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	if (atoi(argv[1]) == 1)
	{
		if (!(list = ft_lstmap(elem, &ft_map)))
			return (0);
		if (list == elem)
			write(1, "A new list is not returned\n", 27);
		while (list)
		{
			ft_print_result(list);
			list = list->next;
		}
	}
	return (0);
}

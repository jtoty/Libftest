#include <stdlib.h>
#include <unistd.h>
#include "../../../libft.h"

void	ft_print_result(t_list *elem)
{
	int		i;

	i = 0;
	while (((char *)elem->content)[i])
	{
		((char *)elem->content)[i] = 'd';
		i++;
	}
	i = 0;
	while (((char *)elem->content)[i])
	{
		write(1, &((char *)elem->content)[i], 1);
		elem->content++;
	}
	write(1, "\n", 1);
}

int main(int argc, const char *argv[])
{
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	char		str [] = "lorem";
	char		str2 [] = "ipsum";
	char		str3 [] = "dolor";
	char		str4 [] = "sit";

	elem = ft_lstnew(str, sizeof(str));
	elem2 = ft_lstnew(str2, sizeof(str2));
	elem3 = ft_lstnew(str3, sizeof(str3));
	elem4 = ft_lstnew(str4, sizeof(str4));
	if (argc == 1 || !elem || !elem2 || !elem3 || !elem4)
		return (0);
	elem->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	if (atoi(argv[1]) == 1)
		ft_lstiter(elem, &ft_print_result);
	return (0);
}

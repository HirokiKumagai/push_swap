/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 00:31:54 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/04 13:19:50 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
void	print_data(t_data *data)
{
	ft_printf(".num		== %d\n", data->num);
	ft_printf(".next		== %p\n", data->next);
}

void	print_list(t_list *list)
{
	ft_printf(".content	== %d\n", *(int *)list->content);
	ft_printf(".next		== %p\n", list->next);
}

int	main(int argc, char const *argv[])
{
	t_data	*data;
	t_list	*arr;
	int		tmp;

	(void) argv;
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (0);
	data->num = 10;
	printf("*data:	%zu\n", sizeof(*data));
	printf("t_data:	%zu\n", sizeof(t_data));
	ft_printf("test\n");
	ft_printf("------------------------\n");
	print_data(data);
	tmp = 10;
	arr = ft_lstnew(&tmp);
	ft_printf("p:	%p\n", arr->content);
	int	*test = (int *)arr->content;
	ft_printf("value:	%d\n", *test);
	t_list *new_arr;
	tmp++;
	new_arr = ft_lstnew(&tmp);
	ft_lstadd_back(&arr, new_arr);
	print_list(new_arr);
	printf("list_count:	%d\n", ft_lstsize(arr));
	free(arr);
	free(data);
	if (argc == 1)
		return (0);
	return (0);
}

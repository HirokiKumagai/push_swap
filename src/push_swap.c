/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 00:31:54 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/06 07:30:56 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
static bool	is_no_args(int argc)
{
	if (argc == 1)
		return (false);
	return (true);
}

void	ft_print_int(void *content)
{
	ft_printf("%d\n", *(int *)content);
}

void	ft_print_str(void *content)
{
	ft_printf("%s\n", (char *)content);
}

int	main(int argc, char const *argv[])
{
	int		**arr;
	t_list	**stack;
	t_list	**empty_stack;

	if (!is_no_args(argc))
		return (false);
	arr = malloc(sizeof(int *) * (argc - 1));
	if (!arr)
		return (0);
	stack = create_stack(argc, argv, arr);
	if (!stack)
		return (0);
	empty_stack = create_empty_stack(argc, stack, arr);
	if (!empty_stack)
		return (0);
	ft_lstiter(stack[0], ft_print_int);
	ft_lstiter(empty_stack[0], ft_print_str);
	free_all_stack(empty_stack, argc - 1);
	free_all_stack(stack, argc - 1);
	free_all_arr(arr, argc - 1);
	return (0);
}

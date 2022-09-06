/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 00:31:54 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/06 02:52:35 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
static bool	is_no_args(int argc)
{
	if (argc == 1)
		return (false);
	return (true);
}

void	ft_test_print(void *content)
{
	ft_printf("%d\n", *(int *)content);
}

int	main(int argc, char const *argv[])
{
	int		**arr;
	t_list	**stack;

	if (!is_no_args(argc))
		return (false);
	arr = malloc(sizeof(int *) * (argc - 1));
	if (!arr)
		return (0);
	stack = create_stack(argc, argv, arr);
	if (!stack)
		return (0);
	ft_lstiter(stack[0], ft_test_print);
	free_all_stack(stack, argc - 1);
	free_all_arr(arr, argc - 1);
	return (0);
}

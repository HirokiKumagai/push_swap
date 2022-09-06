/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 02:40:48 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/06 02:50:42 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
static t_list	**init_stack(int argc, const char *argv[], int **arr)
{
	int		size;
	t_list	**stack;

	size = argc - 1;
	arr = check_args(size, argv, arr);
	if (!arr)
		return (NULL);
	stack = malloc(sizeof(t_list *) * size);
	if (!stack)
	{
		free_all_arr(arr, size);
		return (NULL);
	}
	return (stack);
}

static t_list	**store_stack(int size, t_list **stack, int **arr)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack[i] = ft_lstnew(arr[i]);
		if (!stack[i])
		{
			free_all_stack(stack, i);
			free_all_arr(arr, size);
			return (NULL);
		}
		if (i > 0)
			ft_lstadd_back(&stack[i - 1], stack[i]);
		i++;
	}
	return (stack);
}

t_list	**create_stack(int argc, const char *argv[], int **arr)
{
	t_list	**stack;
	int		size;

	size = argc - 1;
	stack = init_stack(argc, argv, arr);
	if (!stack)
		return (NULL);
	stack = store_stack(size, stack, arr);
	if (!stack)
		return (NULL);
	return (stack);
}

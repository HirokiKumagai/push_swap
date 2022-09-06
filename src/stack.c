/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 02:40:48 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/06 16:54:11 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
static t_list	**init_stack(int argc, int **arr)
{
	int		size;
	t_list	**stack;

	size = argc - 1;
	stack = malloc(sizeof(t_list *) * size);
	if (!stack)
	{
		free_all_arr(arr, size);
		ft_printf("Error\n");
		exit(1);
	}
	return (stack);
}

static t_list	**init_empty_stack(int size, t_list **stack_a, int **arr)
{
	t_list	**stack;

	stack = malloc(sizeof(t_list *) * size);
	if (!stack)
	{
		free_all_stack(stack_a, size);
		free_all_arr(arr, size);
		exit(1);
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
			exit(1);
		}
		if (i > 0)
			ft_lstadd_back(&stack[i - 1], stack[i]);
		i++;
	}
	return (stack);
}

t_list	**create_stack(int argc, int **arr)
{
	t_list	**stack;
	int		size;

	size = argc - 1;
	stack = init_stack(argc, arr);
	if (!stack)
	{
		free_all_arr(arr, size);
		ft_printf("Error\n");
		exit(1);
	}
	stack = store_stack(size, stack, arr);
	if (!stack)
	{
		free_all_arr(arr, size);
		ft_printf("Error\n");
		exit(1);
	}
	return (stack);
}

t_list	**create_empty_stack(int argc, t_list **stack_a, int **arr)
{
	t_list	**stack;
	int		size;
	int		i;

	size = argc - 1;
	stack = init_empty_stack(size, stack_a, arr);
	i = 0;
	while (i < size)
	{
		stack[i] = ft_lstnew(NULL);
		if (!stack[i])
		{
			free_all_stack(stack_a, i);
			free_all_arr(arr, size);
			ft_printf("Error");
			exit(1);
		}
		if (i > 0)
			ft_lstadd_back(&stack[i - 1], stack[i]);
		i++;
	}
	return (stack);
}

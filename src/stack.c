/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 02:40:48 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/14 08:05:01 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
static t_list	**init_stack(int argc, int **arr)
{
	t_list	**stack;
	size_t	size;

	size = argc - 1;
	stack = malloc(sizeof(t_list *));
	if (!stack)
	{
		free_all_arr(arr, size);
		ft_printf("Error\n");
		exit(1);
	}
	return (stack);
}

static t_list	**init_empty_stack(int size, int **arr, t_list **stack_a)
{
	t_list	**stack;

	stack = malloc(sizeof(t_list *));
	if (!stack)
	{
		free_all_stack(stack_a);
		free_all_arr(arr, size);
		exit(1);
	}
	return (stack);
}

static t_list	**store_stack(int size, t_list **stack, int **arr)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (i < size)
	{
		tmp = ft_lstnew(arr[i]);
		if (!tmp)
		{
			free_all_stack(stack);
			free_all_arr(arr, size);
			exit(1);
		}
		if (i == 0)
			*stack = tmp;
		if (i > 0)
			ft_lstadd_back(stack, tmp);
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
	stack = store_stack(size, stack, arr);
	return (stack);
}

t_list	**create_empty_stack(int argc, int **arr, t_list **stack_a)
{
	t_list	**stack;
	int		size;

	size = argc - 1;
	stack = init_empty_stack(size, arr, stack_a);
	return (stack);
}

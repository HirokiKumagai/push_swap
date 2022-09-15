/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 07:26:23 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/15 05:44:22 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
static t_list	**init_sorted_lst(size_t size, \
				int **arr, t_list **stack_a, t_list **stack_b)
{
	t_list	**lst;

	lst = malloc(sizeof(t_list *));
	if (!lst)
	{
		free_all_stack(stack_a);
		free_all_stack(stack_b);
		free_all_arr(arr, size);
		exit(1);
	}
	return (lst);
}

static t_list	**store_lst(int size, int **arr, t_list **stack)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (i < size)
	{
		tmp = ft_lstnew(arr[i]);
		if (!tmp)
			return (NULL);
		if (i == 0)
			*stack = tmp;
		if (i > 0)
			ft_lstadd_back(stack, tmp);
		i++;
	}
	return (stack);
}

static void	**merge_sort(t_list **lst)
{
	t_list	*first_half;
	t_list	*second_half;
	t_list	*x;

	first_half = *lst;
	second_half = (*lst)->next;
	if (second_half != NULL)
		second_half = second_half->next;
	while (second_half != NULL)
	{
		first_half = first_half->next;
		second_half = second_half->next;
		if (second_half != NULL)
			second_half = second_half->next;
	}
	x = first_half->next;
	first_half->next = NULL;
	ft_printf("lst	%d\n", *(int *)(*lst)->content);
	ft_printf("first_half	%d\n", *(int *)first_half->content);
	ft_printf("x	%d\n", *(int *)x->content);
	return (NULL);
}

// static void	merge(t_list **a, t_list **b)
// {
// 	t_list	**x;


// 	while (a != NULL && b != NULL)
// 	{
// 		if (*(int *)(*a)->content <= *(int *)(*b)->content)
// 		{
// 			x->next = a;
// 			x = x->next;
// 			a = a->next;
// 		}
// 		else
// 		{
// 			x->next = b;
// 			x = x->next;
// 			b = b->next;
// 		}
// 	}

// }

t_list	**create_sorted_lst(int argc,
						   int **arr, t_list **stack_a, t_list **stack_b)
{
	t_list	**tmp_lst;
	size_t	size;

	size = argc - 1;
	tmp_lst = init_sorted_lst(size, arr, stack_a, stack_b);
	tmp_lst = store_lst(size, arr, tmp_lst);
	if (!tmp_lst)
	{
		free_all_stack(stack_a);
		free_all_stack(stack_b);
		free_all_arr(arr, size);
		exit(1);
	}
	merge_sort(tmp_lst);
	return (tmp_lst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:23:36 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/13 05:00:58 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
static void	sort_two(t_list **stack_a)
{
	int	first;
	int	second;

	first = *(int *)(*stack_a)->content;
	second = *(int *)(*stack_a)->next->content;
	if (first > second)
		sa(stack_a);
	return ;
}

static void	sort_three(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*stack_a)->content;
	second = *(int *)(*stack_a)->next->content;
	third = *(int *)(*stack_a)->next->next->content;

	// 123
	if (first < second && second < third)
	{
		ft_printf("first:	%d\n", first);
		ft_printf("second:	%d\n", second);
		ft_printf("third:	%d\n", third);
		return;
	}

	// 132
	if (first < third && third < second)
		ra(stack_a);
	// 213
	if (second < first && first < third)
		sa(stack_a);
	// 231
	if (third < first && first < second)
		sa(stack_a);
	// 312
	if (second < third && third < first)
	{
		ft_printf("first:	%d\n", first);
		ft_printf("second:	%d\n", second);
		ft_printf("third:	%d\n", third);
		ra(stack_a);
	}
	// 321
	if (third < second && second < first)
		ra(stack_a);

	sort_three(stack_a);
}
// 1 2 3

// 1 3 2
// 3 2 1
// 2 1 3
// 1 2 3

// 2 1 3
// 1 2 3

// 2 3 1
// 3 2 1
// 2 1 3
// 1 2 3

// 3 1 2
// 1 2 3

// 3 2 1
// 2 1 3
// 1 2 3

void	start_sort(int argc, t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = argc - 1;
	if (size == 1)
		return ;
	if (size == 2)
		return (sort_two(stack_a));
	if (size == 3)
		return (sort_three(stack_a));
	if (3 < size && size < 7)
		return ;
	else
		return ;
	(void)argc;
	(void)stack_a;
	(void)stack_b;
	return ;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:23:36 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/13 07:55:43 by hkumagai         ###   ########.fr       */
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

	if (first < second && second < third)
		return ;
	if (first < third && third < second)
		ra(stack_a);
	if (second < first && first < third)
		sa(stack_a);
	if (third < first && first < second)
		sa(stack_a);
	if (second < third && third < first)
		ra(stack_a);
	if (third < second && second < first)
		ra(stack_a);
	sort_three(stack_a);
}

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


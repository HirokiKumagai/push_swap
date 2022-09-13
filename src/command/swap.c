/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 07:42:07 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/13 07:49:53 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
static bool	common_swap(t_list **stack)
{
	t_list	*first;
	t_list	*third;
	size_t	size;

	size = ft_lstsize(*stack);
	if (size < 2)
		return (false);
	if (!(*stack)->next->next)
		third = NULL;
	else
		third = (*stack)->next->next;
	first = *stack;
	*stack = (*stack)->next;
	(*stack)->next = first;
	first->next = third;
	return (true);
}

bool	sa(t_list **stack_a)
{
	if (!common_swap(stack_a))
		return (false);
	ft_putendl_fd("sa", 1);
	return (true);
}

bool	sb(t_list **stack_b)
{
	if (!common_swap(stack_b))
		return (false);
	ft_putendl_fd("sb", 1);
	return (true);
}

bool	ss(t_list **stack_a, t_list **stack_b)
{
	size_t	size_a;
	size_t	size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	if (size_a < 2 || size_b < 2)
		return (false);
	common_swap(stack_a);
	common_swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (true);
}

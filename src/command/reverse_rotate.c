/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 07:35:15 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/13 07:39:19 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
static bool	common_reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	size_t	size;

	size = ft_lstsize(*stack);
	if (size < 2)
		return (false);
	tmp = ft_lstlast(*stack);
	tmp->next = *stack;
	*stack = tmp;
	while (size)
	{
		if (size == 1)
			(*stack)->next = NULL;
		*stack = (*stack)->next;
		size--;
	}
	*stack = tmp;
	return (true);
}

bool	rra(t_list **stack_a)
{
	if (!common_reverse_rotate(stack_a))
		return (false);
	ft_putendl_fd("rra", 1);
	return (true);
}

bool	rrb(t_list **stack_b)
{
	if (!common_reverse_rotate(stack_b))
		return (false);
	ft_putendl_fd("rrb", 1);
	return (true);
}

bool	rrr(t_list **stack_a, t_list **stack_b)
{
	size_t	size_a;
	size_t	size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	if (size_a < 2 || size_b < 2)
		return (false);
	common_reverse_rotate(stack_a);
	common_reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (true);
}

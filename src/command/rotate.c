/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 07:28:26 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/13 07:32:22 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
static bool	common_rotate(t_list **stack)
{
	t_list	*tmp;

	if (ft_lstsize(*stack) < 2)
		return (false);
	tmp = (*stack)->next;
	(*stack)->next = NULL;
	ft_lstadd_front(stack, tmp);
	return (true);
}

bool	ra(t_list **stack_a)
{
	if (!common_rotate(stack_a))
		return (false);
	ft_putendl_fd("ra", 1);
	return (true);
}

bool	rb(t_list **stack_b)
{
	if (!common_rotate(stack_b))
		return (false);
	ft_putendl_fd("rb", 1);
	return (true);
}

bool	rr(t_list **stack_a, t_list **stack_b)
{
	size_t	size_a;
	size_t	size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	if (size_a < 2 || size_b < 2)
		return (false);
	common_rotate(stack_a);
	common_rotate(stack_b);
	ft_putendl_fd("rr", 1);
	return (true);
}

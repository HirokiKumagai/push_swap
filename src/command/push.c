/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 06:51:40 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/13 07:26:48 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
static bool	common_push(t_list **from_stack, t_list **to_stack)
{
	t_list	*tmp;

	if (ft_lstsize(*from_stack) < 1)
		return (false);
	tmp = *from_stack;
	*from_stack = (*from_stack)->next;
	tmp->next = *to_stack;
	*to_stack = tmp;
	return (true);
}

bool	pb(t_list **stack_a, t_list **stack_b)
{
	if (!common_push(stack_a, stack_b))
		return (false);
	ft_putendl_fd("pb", 1);
	return (true);
}

bool	pa(t_list **stack_a, t_list **stack_b)
{
	if (!common_push(stack_b, stack_a))
		return (false);
	ft_putendl_fd("pa", 1);
	return (true);
}

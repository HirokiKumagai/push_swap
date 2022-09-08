/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:01:31 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/08 13:09:57 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
bool	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_b;

	if (ft_lstsize(*stack_b) < 1)
		return (false);
	tmp_b = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp_b->next = *stack_a;
	*stack_a = tmp_b;
	return (true);
}

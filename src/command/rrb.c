/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:01:45 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/08 16:09:03 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
bool	rrb(t_list **stack_b)
{
	t_list	*tmp_b;
	size_t	size;

	size = ft_lstsize(*stack_b);
	if (size < 2)
		return (false);
	tmp_b = ft_lstlast(*stack_b);
	tmp_b->next = *stack_b;
	*stack_b = tmp_b;
	while (size)
	{
		if (size == 1)
			(*stack_b)->next = NULL;
		*stack_b = (*stack_b)->next;
		size--;
	}
	*stack_b = tmp_b;
	return (true);
}

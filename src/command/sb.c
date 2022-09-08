/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:01:51 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/08 12:22:44 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
bool	sb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;
	size_t	size;

	size = ft_lstsize(*stack_b);
	if (size < 2)
		return (false);
	if (!(*stack_b)->next->next)
		tmp = NULL;
	else
		tmp = (*stack_b)->next->next;
	tmp2 = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->next = tmp2;
	tmp2->next = tmp;
	return (true);
}

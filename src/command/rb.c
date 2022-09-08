/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:01:39 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/08 13:49:59 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
bool	rb(t_list **stack_b)
{
	t_list	*tmp_b;

	if (ft_lstsize(*stack_b) < 2)
		return (false);
	tmp_b = (*stack_b)->next;
	(*stack_b)->next = NULL;
	ft_lstadd_front(stack_b, tmp_b);
	return (true);
}

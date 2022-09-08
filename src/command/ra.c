/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:01:36 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/08 13:49:27 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
bool	ra(t_list **stack_a)
{
	t_list	*tmp_a;

	if (ft_lstsize(*stack_a) < 2)
		return (false);
	tmp_a = (*stack_a)->next;
	(*stack_a)->next = NULL;
	ft_lstadd_front(stack_a, tmp_a);
	return (true);
}

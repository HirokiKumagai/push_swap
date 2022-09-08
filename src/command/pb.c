/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:01:34 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/08 13:13:31 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
bool	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;

	if (ft_lstsize(*stack_a) < 1)
		return (false);
	tmp_a = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp_a->next = *stack_b;
	*stack_b = tmp_a;
	return (true);
}

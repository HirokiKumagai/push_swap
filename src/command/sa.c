/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:46 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/08 12:17:37 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
bool	sa(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;
	size_t	size;

	size = ft_lstsize(*stack_a);
	if (size < 2)
		return (false);
	if (!(*stack_a)->next->next)
		tmp = NULL;
	else
		tmp = (*stack_a)->next->next;
	tmp2 = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->next = tmp2;
	tmp2->next = tmp;
	return (true);
}

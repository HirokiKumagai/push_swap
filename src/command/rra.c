/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:01:43 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/08 16:07:52 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/push_swap.h"
bool	rra(t_list **stack_a)
{
	t_list	*tmp_a;
	size_t	size;

	size = ft_lstsize(*stack_a);
	if (size < 2)
		return (false);
	tmp_a = ft_lstlast(*stack_a);
	tmp_a->next = *stack_a;
	*stack_a = tmp_a;
	while (size)
	{
		if (size == 1)
			(*stack_a)->next = NULL;
		*stack_a = (*stack_a)->next;
		size--;
	}
	*stack_a = tmp_a;
	return (true);
}

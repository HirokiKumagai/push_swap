/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:01:47 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/08 16:10:01 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
bool	rrr(t_list **stack_a, t_list **stack_b)
{
	size_t	size_a;
	size_t	size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	if (size_a < 2 || size_b < 2)
		return (false);
	rra(stack_a);
	rrb(stack_b);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:01:41 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/08 13:51:57 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
bool	rr(t_list **stack_a, t_list **stack_b)
{
	size_t	size_a;
	size_t	size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	if (size_a < 2 || size_b < 2)
		return (false);
	ra(stack_a);
	rb(stack_b);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:46 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/08 02:51:27 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdio.h>
void	sa(t_list **stack_a)
{
	ft_lstadd_front(stack_a, (*stack_a)->next);
	(*stack_a)->next->next = NULL;
	return ;
}

// stack: 		a b c
// tmp:			b c
// stack.next:




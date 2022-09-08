/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 02:09:13 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/08 04:12:10 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
void	free_all_arr(int **arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_all_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*new_stack;

	new_stack = *stack;
	while (new_stack)
	{
		tmp = new_stack->next;
		free(new_stack);
		new_stack = tmp;
	}
	free(stack);
}

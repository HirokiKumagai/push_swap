/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 02:09:13 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/06 02:13:50 by hkumagai         ###   ########.fr       */
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

void	free_all_stack(t_list **stack, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(stack[i]);
		i++;
	}
	free(stack);
}

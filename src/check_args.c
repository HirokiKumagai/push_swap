/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 02:26:27 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/09 17:40:15 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
static bool	is_invalid_num(char *str)
{
	int	sign_count;
	int	status;

	sign_count = 0;
	status = 0;
	while (*str)
	{
		if (*str == '-' && status > 0)
			return (false);
		if (*str == '-')
		{
			sign_count++;
			str++;
			continue ;
		}
		if (sign_count > 1)
			return (false);
		if (ft_isdigit(*str) == false)
			return (false);
		else
			status++;
		str++;
	}
	return (true);
}

// 引数が整数より大きいときのエラー処理が必要
// ft_atoiの改良版が必要
int	**check_args(int size, const char *argv[], int **arr)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!is_invalid_num((char *)argv[i + 1]))
		{
			free_all_arr(arr, i);
			return (NULL);
		}
		arr[i] = malloc(sizeof(int));
		if (!arr[i])
		{
			free_all_arr(arr, i);
			return (NULL);
		}
		*arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (arr);
}

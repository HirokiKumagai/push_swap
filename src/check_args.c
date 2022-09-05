/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 05:08:38 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/05 19:50:29 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
static bool	is_no_args(int argc)
{
	if (argc == 1)
		return (false);
	return (true);
}

static bool	is_invalid_num(char *str)
{
	int	sign_count;

	sign_count = 0;
	while (*str)
	{
		if (*str == '-')
		{
			sign_count++;
			str++;
			continue ;
		}
		if (sign_count > 1)
		{
			ft_printf("ERROR:	Invalid Args\n");
			return (false);
		}
		if (ft_isdigit(*str) == false)
		{
			ft_printf("ERROR:	Invalid Args\n");
			return (false);
		}
		str++;
	}
	return (true);
}

static void	free_all_tmp(int **tmp, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

static void	free_all_stack(t_list **tmp, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

bool	check_args(int argc, char const *argv[])
{
	int		i;
	int		size;
	int		**tmp;
	t_list	**stack;

	if (!is_no_args(argc))
		return (false);
	size = argc - 1;
	tmp = malloc(sizeof(int *) * (size));
	if (!tmp)
	{
		ft_printf("ERROR:	Can't malloc\n");
		return (false);
	}
	i = 0;
	while (i < size)
	{
		if (!is_invalid_num((char *)argv[i + 1]))
		{
			free_all_tmp(tmp, i);
			return (false);
		}
		tmp[i] = malloc(sizeof(int));
		if (!tmp[i])
		{
			free_all_tmp(tmp, i);
			return (NULL);
		}
		// 引数が整数より大きいときのエラー処理が必要
		// ft_atoiの改良版が必要
		*tmp[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	i = 0;
	stack = malloc(sizeof(t_list *) * size);
	if (!stack)
	{
		free_all_tmp(tmp, size);
		return (NULL);
	}
	while (i < size)
	{
		stack[i] = ft_lstnew(tmp[i]);
		if (!stack[i])
		{
			free_all_stack(stack, i);
			free_all_tmp(tmp, size);
			return (NULL);
		}
		if (i > 0)
			ft_lstadd_back(&stack[i - 1], stack[i]);
		ft_printf("%d	\n", *(int *)tmp[i]);
		i++;
	}
	ft_printf("stack_size:	%d\n", ft_lstsize(stack[0]));
	free_all_stack(stack, size);
	free_all_tmp(tmp, size);
	return (true);
}

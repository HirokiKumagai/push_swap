/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 00:31:54 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/06 00:16:47 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
static bool	is_no_args(int argc)
{
	if (argc == 1)
		return (false);
	return (true);
}

static bool is_invalid_num(char *str)
{
	int sign_count;

	sign_count = 0;
	while (*str)
	{
		if (*str == '-')
		{
			sign_count++;
			str++;
			continue;
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

static void free_all_tmp(int **tmp, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

static void free_all_stack(t_list **tmp, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void	ft_test_print(void *content)
{
	ft_printf("%d\n", *(int *)content);
}

int	main(int argc, char const *argv[])
{
	int i;
	int size;
	int **tmp;
	t_list **stack;

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
			return (0);
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
		return (0);
	}
	while (i < size)
	{
		stack[i] = ft_lstnew(tmp[i]);
		if (!stack[i])
		{
			free_all_stack(stack, i);
			free_all_tmp(tmp, size);
			return (0);
		}
		if (i > 0)
			ft_lstadd_back(&stack[i - 1], stack[i]);
		i++;
	}
	ft_lstiter(stack[0], ft_test_print);
	free_all_stack(stack, size);
	free_all_tmp(tmp, size);
	return (0);
}

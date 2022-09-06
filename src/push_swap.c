/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 00:31:54 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/06 16:51:04 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
static bool	is_no_args(int argc)
{
	if (argc == 1)
		return (false);
	return (true);
}

void	ft_print_int(void *content)
{
	ft_printf("%d\n", *(int *)content);
}

void	ft_print_str(void *content)
{
	ft_printf("%s\n", (char *)content);
}

int	**create_arr(int argc, const char *argv[])
{
	int	**arr;
	int	size;

	size = argc - 1;
	arr = malloc(sizeof(int *) * size);
	if (!arr)
	{
		ft_printf("Error\n");
		exit(1);
	}
	arr = check_args(size, argv, arr);
	if (!arr)
	{
		ft_printf("Error\n");
		exit(1);
	}
	return (arr);
}

int	main(int argc, char const *argv[])
{
	int		**arr;
	t_list	**stack;
	t_list	**empty_stack;

	if (!is_no_args(argc))
		return (false);
	arr = create_arr(argc, argv);
	stack = create_stack(argc, arr);
	empty_stack = create_empty_stack(argc, stack, arr);
	ft_lstiter(stack[0], ft_print_int);
	ft_lstiter(empty_stack[0], ft_print_str);
	free_all_stack(empty_stack, argc - 1);
	free_all_stack(stack, argc - 1);
	free_all_arr(arr, argc - 1);
	return (0);
}

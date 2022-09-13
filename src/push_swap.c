/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 00:31:54 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/13 07:51:12 by hkumagai         ###   ########.fr       */
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
	if (content)
		ft_printf("%d\n", *(int *)content);
	else
		ft_printf("null\n");
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
	t_list	**stack_a;
	t_list	**stack_b;

	if (!is_no_args(argc))
		return (false);
	arr = create_arr(argc, argv);
	stack_a = create_stack(argc, arr);
	stack_b = create_empty_stack(argc, stack_a, arr);
	ft_printf("----------before:	stack_ab----------\n");
	ft_printf("----------after:	stack_a----------\n");
	ft_lstiter(*stack_a, ft_print_int);
	ft_printf("----------after:	stack_b----------\n");
	ft_lstiter(*stack_b, ft_print_int);
	ft_printf("----------command:	start----------\n");
	start_sort(argc, stack_a, stack_b);
	// pb(stack_a, stack_b);
	// pb(stack_a, stack_b);
	// pb(stack_a, stack_b);
	// ra(stack_a);
	// ra(stack_a);
	// rra(stack_a);
	// ra(stack_a);
	// sa(stack_a);
	// ra(stack_a);
	ft_printf("----------command:	end----------\n");
	ft_printf("----------after:	stack_ab----------\n");
	ft_printf("----------after:	stack_a----------\n");
	ft_lstiter(*stack_a, ft_print_int);
	ft_printf("----------after:	stack_b----------\n");
	ft_lstiter(*stack_b, ft_print_int);
	free_all_stack(stack_b);
	free_all_stack(stack_a);
	free_all_arr(arr, argc - 1);
	return (0);
}

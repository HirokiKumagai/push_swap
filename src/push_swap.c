/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 00:31:54 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/05 03:55:50 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	check_args(int argc, char const *argv[])
{
	int		i;
	int		sign_count;
	char	*str;

	i = 1;
	sign_count = 0;
	str = "";
	if (argc == 1)
	{
		ft_printf("ERROR:	No Args\n");
		return (false);
	}
	while (i < argc)
	{
		str = (char *)argv[i];
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
		i++;
	}
	return (true);
}

int	main(int argc, char const *argv[])
{
	if (!check_args(argc, argv))
		return (0);
	ft_printf("success\n");
	return (0);
}

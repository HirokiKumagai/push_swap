/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 07:45:27 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/14 08:42:03 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGE_SORT_H
# define MERGE_SORT_H
# include "../lib/libft/include/libft.h"
t_list	**create_sorted_lst(int argc, \
			int **arr, t_list **stack_a, t_list **stack_b);
#endif

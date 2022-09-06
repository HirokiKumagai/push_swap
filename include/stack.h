/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 02:40:09 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/06 16:28:25 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
t_list	**create_stack(int argc, int **arr);
t_list	**create_empty_stack(int argc, t_list **stack_a, int **arr);
#endif

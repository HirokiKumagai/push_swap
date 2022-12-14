/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:01:27 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/08 14:01:49 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H
bool	sa(t_list **stack_a);
bool	sb(t_list **stack_b);
bool	ss(t_list **stack_a, t_list **stack_b);
bool	pa(t_list **stack_a, t_list **stack_b);
bool	pb(t_list **stack_a, t_list **stack_b);
bool	ra(t_list **stack_a);
bool	rb(t_list **stack_b);
bool	rr(t_list **stack_a, t_list **stack_b);
bool	rra(t_list **stack_a);
bool	rrb(t_list **stack_b);
bool	rrr(t_list **stack_a, t_list **stack_b);
#endif

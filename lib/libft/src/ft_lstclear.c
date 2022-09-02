/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkumagai <hkumagai@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:26:43 by hkumagai          #+#    #+#             */
/*   Updated: 2022/09/02 07:36:22 by hkumagai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new_lst;

	if (!del)
		return ;
	new_lst = *lst;
	while (new_lst)
	{
		tmp = new_lst->next;
		del(new_lst->content);
		free(new_lst);
		new_lst = tmp;
	}
	*lst = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:24:30 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/09 12:04:34 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst_new(int data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->num = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_list	*ft_lst_last(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	return (ptr);
}

void	dlst_add_front(t_list **lst, t_list *node)
{
	node->next = *lst;
	if (*lst)
		(*lst)->prev = node;
	*lst = node;
	(*lst)->prev = NULL;
}

void	dlst_add_back(t_list **lst, t_list *node)
{
	t_list	*last;

	if (!lst || !node)
		return ;
	if (*lst == NULL)
		*lst = node;
	else
	{
		last = ft_lst_last(*lst);
		last->next = node;
		node->prev = last;
	}
	node->next = NULL;
}

void	clear_list(t_list *lst)
{
	t_list	*ptr;

	ptr = lst;
	while (ptr)
	{
		lst = lst->next;
		free(ptr);
		ptr = lst;
	}
}

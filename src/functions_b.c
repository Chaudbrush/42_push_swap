/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:14:23 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/13 10:40:29 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_b(t_list **lst, int flag)
{
	t_list	*first;
	t_print	*commands;

	if (!*lst || !(*lst)->next)
		return ;
	commands = output_parse();
	first = *lst;
	*lst = (*lst)->next;
	(*lst)->prev = NULL;
	dlst_add_back(lst, first);
	if (flag)
		ft_lstadd_back(&commands, ft_lst_new_single("rb\n"));
}

void	rev_rotate_b(t_list **lst, int flag)
{
	t_list	*last;
	t_print	*commands;

	if (!*lst || !(*lst)->next)
		return ;
	commands = output_parse();
	last = ft_lst_last(*lst);
	last->prev->next = NULL;
	dlst_add_front(lst, last);
	if (flag)
		ft_lstadd_back(&commands, ft_lst_new_single("rrb\n"));
}

void	swap_b(t_list **lst, int flag)
{
	int		tmp;
	t_print	*commands;

	if (!*lst || !(*lst)->next)
		return ;
	commands = output_parse();
	tmp = (*lst)->num;
	(*lst)->num = (*lst)->next->num;
	(*lst)->next->num = tmp;
	if (flag)
		ft_lstadd_back(&commands, ft_lst_new_single("sa\n"));
}

void	push_b(t_list **a, t_list **b, int flag)
{
	t_list	*ptr;
	t_print	*commands;

	if (!*a)
		return ;
	commands = output_parse();
	ptr = *a;
	*a = (*a)->next;
	dlst_add_front(b, ptr);
	if (flag)
		ft_lstadd_back(&commands, ft_lst_new_single("pb\n"));
}

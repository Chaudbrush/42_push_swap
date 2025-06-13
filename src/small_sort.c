/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 14:29:26 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/13 10:41:33 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_list **lst)
{
	int		biggest;

	biggest = find_biggest(*lst);
	if ((*lst)->num == biggest)
		rotate_a(lst, 1);
	else if ((*lst)->next->num == biggest)
		rev_rotate_a(lst, 1);
	if ((*lst)->num > (*lst)->next->num)
		swap_a(lst, 1);
}

void	sort_four_five(t_list **a, t_list **b, int n)
{
	int	pos;
	int	push;
	int	lowest;

	push = 0;
	while (push < n)
	{
		lowest = find_lowest(*a);
		pos = get_position(*a, lowest);
		while ((*a)->num != lowest)
		{
			if (pos <= 2)
				rotate_a(a, 1);
			else
				rev_rotate_a(a, 1);
		}
		push_b(a, b, 1);
		push++;
	}
	sort_three(a);
	push_a(a, b, 1);
	push_a(a, b, 1);
}

int	find_biggest(t_list *lst)
{
	int	biggest;

	biggest = INT_MIN;
	while (lst)
	{
		if (lst->num > biggest)
			biggest = lst->num;
		lst = lst->next;
	}
	return (biggest);
}

int	find_lowest(t_list *lst)
{
	int	lowest;

	lowest = INT_MAX;
	while (lst)
	{
		if (lst->num < lowest)
			lowest = lst->num;
		lst = lst->next;
	}
	return (lowest);
}

int	get_position(t_list *lst, int num)
{
	int	position;

	position = 0;
	while (lst)
	{
		if (lst->num == num)
			break ;
		position++;
		lst = lst->next;
	}
	return (position);
}

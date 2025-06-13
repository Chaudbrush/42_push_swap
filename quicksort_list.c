/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:03:52 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/12 21:18:36 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fake_quicksort(t_list **a, t_list **b)
{
	int		size;
	int		chunk;
	int		pivot;
	int		median;
	float	n;

	size = ft_lst_size(*a);
	if (size < 200)
		n = 0.30;
	else
		n = 0.14;
	chunk = size * n;
	pivot = chunk;
	median = pivot / 2;
	while (pivot <= size || *a)
	{
		from_a_to_b(a, b, pivot, median);
		pivot = pivot + chunk;
		median = median + chunk;
		if (ft_lst_size(*a) == 3)
			break ;
	}
	sort_three(a);
	from_b_to_a(a, b);
}

void	from_a_to_b(t_list **a, t_list **b, int pivot, int median)
{
	int			biggest;
	static int	i;

	biggest = find_biggest(*a);
	while (i < pivot && *a)
	{
		if ((*a)->num >= pivot || (*a)->num >= biggest -2)
			rotate_a(a, 1);
		else
		{
			push_b(a, b, 1);
			if ((*b)->num < median)
				rotate_b(b, 1);
			i++;
		}
		if (ft_lst_size(*a) == 3)
			break ;
	}
}

void	from_b_to_a(t_list **a, t_list **b)
{
	int			size;
	t_compare	value[3];

	size = ft_lst_size(*b);
	while (size > 1)
	{
		find_two_biggest(*b, value);
		find_price(*b, value);
		move_min_to_top(b, value);
		if (*a)
		{
			if ((*a)->num == (*b)->num + 1 || (*a)->num == (*b)->num - 1)
				push_a(a, b, 1);
			else
				correct_and_push(a, b);
		}
		else
			push_a(a, b, 1);
		if (*a && (*a)->next && (*a)->num > (*a)->next->num)
			swap_a(a, 1);
		size--;
	}
	correct_and_push(a, b);
}

void	move_min_to_top(t_list **b, t_compare *value)
{
	if (my_abs(value[0].price) < my_abs(value[1].price))
	{
		value[2].biggest = value[0].biggest;
		value[2].price = value[0].price;
	}
	else
	{
		value[2].biggest = value[1].biggest;
		value[2].price = value[1].price;
	}
	while ((*b)->num != value[2].biggest)
	{
		if (value[2].price > 0)
			rotate_b(b, 1);
		else
			rev_rotate_b(b, 1);
	}
}

void	correct_and_push(t_list **a, t_list **b)
{
	int	rotates;

	rotates = 0;
	while ((*a)->num < (*b)->num)
	{
		rotate_a(a, 1);
		rotates++;
	}
	push_a(a, b, 1);
	while (rotates)
	{
		rev_rotate_a(a, 1);
		rotates--;
	}
}

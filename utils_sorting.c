/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 12:27:35 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/10 13:11:47 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_abs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

void	find_price(t_list *lst, t_compare *array)
{
	int	i;
	int	median;
	int	size;

	i = 0;
	size = ft_lst_size(lst);
	median = size / 2;
	while (lst)
	{
		if (lst->num == array[0].biggest)
			array[0].price = i;
		else if (lst->num == array[1].biggest)
			array[1].price = i;
		i++;
		lst = lst->next;
	}
	if (array[0].price > median)
		array[0].price = array[0].price - size;
	if (array[1].price > median)
		array[1].price = array[1].price - size;
}

void	find_two_biggest(t_list *lst, t_compare *array)
{
	array[0].biggest = INT_MIN;
	array[1].biggest = INT_MIN;
	while (lst)
	{
		if (lst->num > array[0].biggest || lst->num > array[1].biggest)
		{
			if (array[1].biggest > array[0].biggest)
				array[0].biggest = array[1].biggest;
			array[1].biggest = lst->num;
		}
		lst = lst->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:37:21 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/05 20:12:11 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(int *array, int start, int end)
{
	int	partition;

	if (start >= end)
		return ;
	partition = ft_partition(array, start, end);
	quick_sort(array, start, partition - 1);
	quick_sort(array, partition + 1, end);
}

int	ft_partition(int *array, int start, int end)
{
	int	i;
	int	j;

	j = start;
	i = j - 1;
	while (j < end)
	{
		if (array[j] < array[end])
		{
			i++;
			ft_swap(&array[i], &array[j]);
		}
		j++;
	}
	i++;
	ft_swap(&array[i], &array[end]);
	return (i);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

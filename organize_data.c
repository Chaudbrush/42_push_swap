/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:26:48 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/09 12:00:10 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_array_and_organize(t_list *lst)
{
	int		i;
	int		size;
	int		*array;
	t_list	*ptr;

	i = 0;
	ptr = lst;
	size = ft_lst_size(lst);
	array = malloc(sizeof(int) * size);
	if (!array)
		return (-1);
	while (ptr)
	{
		array[i] = ptr->num;
		ptr = ptr->next;
		i++;
	}
	quick_sort(array, 0, size - 1);
	normalize_numbers(lst, array, size);
	free(array);
	return (0);
}

void	normalize_numbers(t_list *lst, int *array, int size)
{
	int		i;

	while (lst)
	{
		i = 0;
		while (i < size)
		{
			if (lst->num == array[i])
			{
				lst->num = i;
				break ;
			}
			i++;
		}
		lst = lst->next;
	}
}

int	ft_lst_size(t_list *lst)
{
	int		i;
	t_list	*ptr;

	i = 0;
	ptr = lst;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

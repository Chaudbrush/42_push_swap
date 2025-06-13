/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:04:38 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/10 14:56:52 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_invalid(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1])
		i++;
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-') && \
			str[i - 1] == ' ' && is_num(str[i + 1]))
			i++;
		else if (is_num(str[i]) || str[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_double(t_list *lst, int n)
{
	while (lst)
	{
		if (lst->num == n)
			return (1);
		lst = lst->next;
	}
	return (0);
}

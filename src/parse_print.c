/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:04:01 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/13 10:41:22 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_print	*output_parse(void)
{
	static t_print	commands;

	return (&commands);
}

void	print_commands(t_print *commands)
{
	t_print	*ptr;

	ptr = commands;
	ptr = ptr->next;
	while (ptr->next)
	{
		if (check_cases(ptr) == 1)
		{
			ft_putstr("rr\n");
			ptr = ptr->next;
		}
		else if (check_cases(ptr) == 2)
		{
			ft_putstr("rrr\n");
			ptr = ptr->next;
		}
		else
			ft_putstr(ptr->str);
		ptr = ptr->next;
	}
	ft_putstr(ptr->str);
}

int	check_cases(t_print *lst)
{
	if (!ft_strcmp(lst->str, "ra\n") && \
		!ft_strcmp(lst->next->str, "rb\n"))
		return (1);
	else if (!ft_strcmp(lst->str, "rb\n") && \
			!ft_strcmp(lst->next->str, "ra\n"))
		return (1);
	else if (!ft_strcmp(lst->str, "rra\n") && \
			!ft_strcmp(lst->next->str, "rrb\n"))
		return (2);
	else if (!ft_strcmp(lst->str, "rrb\n") && \
			!ft_strcmp(lst->next->str, "rra\n"))
		return (2);
	else
		return (0);
}

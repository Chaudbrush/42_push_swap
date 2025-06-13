/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:39:38 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/12 15:45:09 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "./get_next_line/get_next_line.h"

int	main(int argc, char **argv)
{
	int		i;
	t_list	*a;
	t_list	*b;
	t_list	*node;

	if (argc == 1)
		return (1);
	i = 0;
	a = NULL;
	b = NULL;
	node = NULL;
	while (++i < argc)
	{
		if (check_invalid(argv[i]) || split_to_int(&a, node, argv[i], 0) == -1)
		{
			write(2, "Error\n", 6);
			return (free_allocs(a, b), 1);
		}
	}
	get_input_and_check(&a, &b);
	free_allocs(a, b);
}

int	split_to_int(t_list **lst, t_list *node, char *str, int i)
{
	int		sign;
	long	num;

	while (str[i])
	{
		sign = 1;
		num = 0;
		while (str[i] == ' ' || str[i] == '+')
			i++;
		if (str[i] == '\0')
			break ;
		if (str[i] == '-')
		{
			i++;
			sign = -sign;
		}
		while (str[i] >= '0' && str[i] <= '9')
			num = (num * 10) + (str[i++] - '0');
		num *= sign;
		if (num > 2147483647 || num < -2147483648 || check_double(*lst, num))
			return (-1);
		node = ft_lst_new(num);
		dlst_add_back(lst, node);
	}
	return (0);
}

int	check_sorted(t_list *a, t_list *b)
{
	t_list	*ptr;

	if (b)
		return (0);
	ptr = a;
	while (ptr->next)
	{
		if (ptr->num > ptr->next->num)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

void	free_allocs(t_list *a, t_list *b)
{
	clear_list(a);
	clear_list(b);
}

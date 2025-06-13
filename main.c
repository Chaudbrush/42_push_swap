/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 14:01:46 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/12 21:15:32 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (check_sorted(a, b))
		return (free_allocs(a, b), 0);
	if (init_array_and_organize(a) == -1)
		return (free_allocs(a, b), 1);
	choose_sort(&a, &b);
	free_allocs(a, b);
}

void	choose_sort(t_list **a, t_list **b)
{
	int		size;
	t_print	*commands;

	commands = output_parse();
	size = ft_lst_size(*a);
	if (size == 2)
		swap_a(a, 1);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four_five(a, b, 1);
	else if (size == 5)
		sort_four_five(a, b, 2);
	else if (size > 5)
		fake_quicksort(a, b);
	print_commands(commands);
	clear_print(commands);
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
		{
			return (0);
		}
		ptr = ptr->next;
	}
	return (1);
}

void	free_allocs(t_list *a, t_list *b)
{
	clear_list(a);
	clear_list(b);
}

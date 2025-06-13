/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 22:08:14 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/13 10:41:43 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"
#include "../get_next_line/get_next_line.h"

void	get_input_and_check(t_list **a, t_list **b)
{
	int		size;
	char	*line;

	line = "start";
	size = ft_lst_size(*a);
	while (line)
	{
		line = get_next_line(STDIN_FILENO);
		execute_commands(line, a, b);
		free(line);
	}
	if (check_full(*a, *b, size))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	execute_commands(char *command, t_list **a, t_list **b)
{
	if (command == NULL)
		return ;
	if (!ft_strncmp(command, "ra\n", 4))
		rotate_a(a, 0);
	else if (!ft_strncmp(command, "rra\n", 5))
		rev_rotate_a(a, 0);
	else if (!ft_strncmp(command, "sa\n", 4))
		swap_a(a, 0);
	else if (!ft_strncmp(command, "pa\n", 4))
		push_a(a, b, 0);
	else if (!ft_strncmp(command, "rb\n", 4))
		rotate_b(b, 0);
	else if (!ft_strncmp(command, "rrb\n", 5))
		rev_rotate_b(b, 0);
	else if (!ft_strncmp(command, "sb\n", 4))
		swap_b(b, 0);
	else if (!ft_strncmp(command, "pb\n", 4))
		push_b(a, b, 0);
	else
		extra_cases(command, a, b);
}

void	extra_cases(char *command, t_list **a, t_list **b)
{
	if (!ft_strncmp(command, "rr\n", 4))
	{
		rotate_a(a, 0);
		rotate_b(b, 0);
	}
	else if (!ft_strncmp(command, "rrr\n", 5))
	{
		rev_rotate_a(a, 0);
		rev_rotate_b(b, 0);
	}
	else if (!ft_strncmp(command, "ss\n", 4))
	{
		swap_a(a, 0);
		swap_b(b, 0);
	}
	else
	{
		write(2, "Error\n", 6);
		free_allocs(*a, *b);
		free(command);
		exit(1);
	}
}

int	check_full(t_list *a, t_list *b, int size_ref)
{
	int		size;
	t_list	*ptr;

	if (b)
		return (0);
	size = ft_lst_size(a);
	if (size != size_ref)
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:53:13 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/12 14:53:20 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_lstadd_back(t_print **lst, t_print *node)
{
	t_print	*last;

	if (!lst || !node)
		return ;
	if (*lst == NULL)
		*lst = node;
	else
	{
		while ((*lst)->next)
			(*lst) = (*lst)->next;
		last = *lst;
		last->next = node;
	}
	node->next = NULL;
}

t_print	*ft_lst_new_single(char *data)
{
	t_print	*new;

	new = malloc(sizeof(t_print));
	if (!new)
		return (NULL);
	new->str = data;
	new->next = NULL;
	return (new);
}

void	clear_print(t_print *lst)
{
	t_print	*ptr;

	lst = lst->next;
	ptr = lst;
	while (ptr)
	{
		lst = lst->next;
		free(ptr);
		ptr = lst;
	}
}

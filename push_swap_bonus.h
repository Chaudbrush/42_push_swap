/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:40:55 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/12 13:14:20 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "push_swap.h"

// Checker Utils
void	get_input_and_check(t_list **a, t_list **b);
int		check_full(t_list *a, t_list *b, int size_ref);
void	extra_cases(char *command, t_list **a, t_list **b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	execute_commands(char *command, t_list **a, t_list **b);

#endif

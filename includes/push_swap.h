/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloureir <vloureir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:40:55 by vloureir          #+#    #+#             */
/*   Updated: 2025/06/13 10:44:47 by vloureir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_print
{
	char			*str;
	struct s_print	*next;
}					t_print;

typedef struct s_compare
{
	int	biggest;
	int	price;
}		t_compare;

typedef struct s_list
{
	int				num;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

// Main
void	free_allocs(t_list *a, t_list *b);
int		check_sorted(t_list *a, t_list *b);
void	choose_sort(t_list **a, t_list **b);
int		split_to_int(t_list **lst, t_list *node, char *str, int i);

// Parse Data
int		is_num(char c);
int		check_invalid(char *str);
int		check_double(t_list *lst, int n);

// Organize Data
int		ft_lst_size(t_list *lst);
int		init_array_and_organize(t_list *lst);
void	normalize_numbers(t_list *lst, int *array, int size);

// List Utils
t_list	*ft_lst_new(int data);
void	clear_list(t_list *lst);
t_list	*ft_lst_last(t_list *list);
void	dlst_add_back(t_list **lst, t_list *node);
void	dlst_add_front(t_list **lst, t_list *node);

// Function A
void	swap_a(t_list **lst, int flag);
void	rotate_a(t_list **lst, int flag);
void	rev_rotate_a(t_list **lst, int flag);
void	push_a(t_list **a, t_list **b, int flag);

// Function B
void	swap_b(t_list **lst, int flag);
void	rotate_b(t_list **lst, int flag);
void	rev_rotate_b(t_list **lst, int flag);
void	push_b(t_list **a, t_list **b, int flag);

// Sorting Utils
int		my_abs(int a);
void	find_price(t_list *lst, t_compare *array);
void	find_two_biggest(t_list *lst, t_compare *array);

// Quicksort Array
void	ft_swap(int *a, int *b);
void	quick_sort(int *array, int start, int end);
int		ft_partition(int *array, int start, int end);

// Small Sort
void	sort_three(t_list **lst);
int		find_lowest(t_list *lst);
int		find_biggest(t_list *lst);
int		get_position(t_list *lst, int num);
void	sort_four_five(t_list **a, t_list **b, int n);

// Quicksort List
void	from_b_to_a(t_list **a, t_list **b);
void	fake_quicksort(t_list **a, t_list **b);
void	correct_and_push(t_list **a, t_list **b);
void	move_min_to_top(t_list **b, t_compare *value);
void	from_a_to_b(t_list **a, t_list **b, int pivot, int median);

// Parse Print
t_print	*output_parse(void);
int		check_cases(t_print *lst);
void	print_commands(t_print *commands);

// Print Utils
void	ft_putstr(char *str);
void	clear_print(t_print *lst);
int		ft_strcmp(char *s1, char *s2);
t_print	*ft_lst_new_single(char *data);
void	ft_lstadd_back(t_print **lst, t_print *node);

// Checker Utils
void	get_input_and_check(t_list **a, t_list **b);
int		check_full(t_list *a, t_list *b, int size_ref);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	execute_commands(char *command, t_list **a, t_list **b);

#endif

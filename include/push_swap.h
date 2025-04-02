/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:19:24 by halzamma          #+#    #+#             */
/*   Updated: 2025/04/02 12:53:33 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				nb;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

// Stack operations
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);

// Stack utilities
t_stack	*init_stack(void);
void	push_to_stack(t_stack *stack, int value);
void	fill_stack(t_stack *a, char *argv[]);
int		stack_size(t_stack *stack);
void	fill_stack_string(t_stack *a, char *arg);

// sorts
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
int		find_min_index(t_stack *a);
void	move_min_to_top(t_stack *a, int min_index);
void	radix_sort(t_stack *a, t_stack *b, int chunks);
int		*stack_to_array(t_stack *a);
void	fill_values(t_stack *a, char *argv[]);
void	assign_indexes(t_stack *a);
long	ft_atol(const char *str);
int		get_index(int *sorted, int value, int size);
void	sort_array(int *arr, int size);
int		find_max_index(t_stack *b);
void	move_max_to_top(t_stack *b, int max_index);
void	push_back_to_a(t_stack *a, t_stack *b);

// check
int		check_args(int argc, char *argv[]);
int		check_duplicates(int argc, char *argv[]);
int		check_sorted(int argc, char *argv[]);
int		check_args(int argc, char *argv[]);
int		is_sorted(t_stack *stack);
int		is_valid(int argc, char **argv);
int		check_string(char *str);

#endif
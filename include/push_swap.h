/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:19:24 by halzamma          #+#    #+#             */
/*   Updated: 2025/02/25 23:19:24 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
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
void	fill_stack(t_stack *a, char **argv);

// sorts
void	sort_stack(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
void	insertion_sort(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);

// check
int		check_valid(int argc, char **argv);
int		check_double(int nb, t_stack *a);
int		check_args(char **argv, t_stack *a);
int		check_sorted(t_stack *a);

#endif
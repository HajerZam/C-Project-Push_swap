/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:19:08 by halzamma          #+#    #+#             */
/*   Updated: 2025/03/05 12:19:08 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// swap for 3 elements
void	sort_three(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
	if (a->top->next->value > a->top->next->next->value)
	{
		rra(a);
		if (a->top->value > a->top->next->value)
			sa(a);
	}
}

// Selection Sort for ~5 elements
void	sort_five(t_stack *a, t_stack *b)
{
	int	min_index;

	while (stack_size(a) > 3)
	{
		min_index = find_min_index(a);
		move_to_top(a, min_index);
		pb(a, b);// Push the smallest element to B
	}
	sort_three(a);// Sort remaining three elements
	while (!stack_is_empty(b))
		pa(a, b);// Push elements back from B to A
}

// Insertion Sort optimized with Stack B
void	insertion_sort(t_stack *a, t_stack *b)
{
	int	value;

	while (!stack_is_empty(a))
	{
		value = a->top->value;
		pb(a, b);// Push to B plus keeping it sorted
		if (b->top->next && b->top->value > b->top->next->value)
			sb(b);
	}
	while (!stack_is_empty(b))
		pa(a, b);// Push back in sorted order
}

// Radix Sort for large numbers
void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	max_bits = get_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		size = stack_size(a);
		j = 0;
		while (j < size)
		{
			if ((a->top->value >> i) & 1)
				ra(a);// If bit is 1, rotate to bottom
			else
				pb(a, b);// If bit is 0, push to B
			j++;
		}
		while (!stack_is_empty(b))
			pa(a, b);// Push back all from B to A
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:43:47 by halzamma          #+#    #+#             */
/*   Updated: 2025/03/21 14:43:47 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Internal helper: Finds the index of the first element in stack A
** that falls within the range [min, max].
*/
static int	find_target_index(t_stack *a, int min, int max)
{
	int		index;
	t_node	*current;

	index = 0;
	current = a->top;
	while (current)
	{
		if (current->nb >= min && current->nb <= max)
			return (index);
		index++;
		current = current->next;
	}
	return (-1);
}

/*
** Internal helper: Rotates stack A in the direction that brings
** the element at target_index to the top using the fewest moves.
*/
static void	greedy_rotate_a(t_stack *a, int target_index)
{
	if (target_index == -1)
		return ;
	if (target_index <= a->size / 2)
	{
		while (target_index-- > 0)
			ra(a);
	}
	else
	{
		target_index = a->size - target_index;
		while (target_index-- > 0)
			rra(a);
	}
}

/*
** Internal helper: Pushes all elements from A that fall within [min, max]
** to stack B using a greedy rotation strategy.
*/
static void	optimized_chunk_push_b(t_stack *a, t_stack *b, int min, int max)
{
	int	target_index;
	int	midpoint;
	int	initial_size;
	int	moves;

	midpoint = (min + max) / 2;
	initial_size = a->size;
	moves = 0;
	target_index = find_target_index(a, min, max);
	while (target_index != -1 && moves < initial_size)
	{
		target_index = find_target_index(a, min, max);
		greedy_rotate_a(a, target_index);
		if (a->top->nb >= min && a->top->nb <= max)
		{
			pb(a, b);
			moves++;
			if (b->size > 1 && b->top->nb < midpoint)
				rb(b);
		}
		else
			moves++;
	}
}

/*
** Splits stack A into chunks (by index range) and pushes each chunk to B
** using an optimized push.
*/

void	split_and_push_chunks(t_stack *a, t_stack *b, int chunks)
{
	int	size;
	int	chunk_size;
	int	current_chunk;
	int	min;
	int	max;

	size = a->size;
	chunk_size = size / chunks;
	current_chunk = 0;
	while (current_chunk < chunks)
	{
		min = current_chunk * chunk_size;
		max = (current_chunk + 1) * chunk_size;
		if (current_chunk == chunks - 1)
			max = size;
		optimized_chunk_push_b(a, b, min, max);
		current_chunk++;
	}
}

/*
** Sorts stack A using radix sort, split_and_push_chunks to handle chunking.
*/
void	radix_sort(t_stack *a, t_stack *b, int chunks)
{
	int	size;

	size = a->size;
	if (size > 300)
	{
		if (size > 500)
			chunks = 11;
		else
			chunks = 9;
	}
	split_and_push_chunks(a, b, chunks);
	push_back_to_a(a, b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 16:13:09 by halzamma          #+#    #+#             */
/*   Updated: 2025/03/24 16:13:09 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_max_index(t_stack *b)
{
	int		max_index;
	int		i;
	t_node	*current;
	int		max;

	if (!b || !b->top)
		return (-1);
	max = b->top->nb;
	max_index = 0;
	i = 0;
	current = b->top;
	while (current)
	{
		if (current->nb > max)
		{
			max = current->nb;
			max_index = i;
		}
		current = current->next;
		i++;
	}
	return (max_index);
}

void	move_max_to_top(t_stack *b, int max_index)
{
	int	i;
	int	moves;

	i = 0;
	if (!b || b->size == 0 || max_index == -1)
		return ;
	if (max_index <= b->size / 2)
	{
		while (i < max_index)
		{
			rb(b);
			i++;
		}
	}
	else
	{
		moves = b->size - max_index;
		while (i < moves)
		{
			rrb(b);
			i++;
		}
	}
}

/*
** push_back_to_a: Pushes all elements from stack B back to stack A,
** always moving the maximum element first.
*/
void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	max_index;

	while (b->size > 0)
	{
		max_index = find_max_index(b);
		move_max_to_top(b, max_index);
		pa(a, b);
		if (a->size > 1 && a->top->nb > a->top->next->nb)
			sa(a);
	}
}

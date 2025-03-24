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

int	find_max_bits(t_stack *a)
{
	int		max_bits;
	int		max;
	t_node	*current;

	if (!a || !a->top)
		return (0);
	max = 0;
	current = a->top;
	while (current)
	{
		if (current->nb > max)
			max = current->nb;
		current = current->next;
	}
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_push_b(t_stack *a, t_stack *b, int bit_pos)
{
	int	stack_size;
	int	j;

	stack_size = a->size;
	j = 0;
	while (j < stack_size)
	{
		if (((a->top->nb >> bit_pos) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		j++;
	}
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int		max_bits;
	int		i;

	if (!a || !a->top || a->size < 2)
		return ;
	max_bits = find_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		radix_push_b(a, b, i);
		while (b->size > 0)
			pa(a, b);
		i++;
	}
}

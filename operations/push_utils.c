/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:23:21 by halzamma          #+#    #+#             */
/*   Updated: 2025/02/25 23:23:21 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return;
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	int	nb;

	if (b->size < 1)
		return;
	nb = pop(b);
	push(a, nb);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	int	nb;

	if (a->size < 1)
		return;
	nb = pop(a);
	push(b, nb);
	write(1, "pb\n", 3);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:07:04 by halzamma          #+#    #+#             */
/*   Updated: 2025/03/24 12:54:41 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/ft_printf.h"

int	pop(t_stack *stack)
{
	int		value;
	t_node	*temp;

	if (!stack || !stack->top)
		return (0);
	temp = stack->top;
	value = temp->nb;
	stack->top = temp->next;
	free(temp);
	stack->size--;
	return (value);
}

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->nb = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:25:50 by halzamma          #+#    #+#             */
/*   Updated: 2025/02/25 23:25:50 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/ft_printf.h"

void	ra(t_stack *a)
{
	t_node	*tmp;
	t_node	*last;

	if (a->size < 2)
		return ;
	tmp = a->top;
	a->top = a->top->next;
	tmp->next = NULL;
	last = a->top;
	while (last->next)
		last = last->next;
	last->next = tmp;
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	t_node	*tmp;
	t_node	*last;

	if (b->size < 2)
		return ;
	tmp = b->top;
	b->top = b->top->next;
	tmp->next = NULL;
	last = b->top;
	while (last->next)
		last = last->next;
	last->next = tmp;
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}

void	rra(t_stack *a)
{
	t_node	*prev;
	t_node	*last;

	if (a->size < 2)
		return ;
	prev = NULL;
	last = a->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = a->top;
	a->top = last;
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	t_node	*prev;
	t_node	*last;

	if (b->size < 2)
		return ;
	prev = NULL;
	last = b->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = b->top;
	b->top = last;
	ft_printf("rrb\n");
}

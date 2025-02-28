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

#include "push_swap.h"

void	ra(t_stack *a)
{
    t_node	*tmp;
	t_node	*last;

    if (a->size < 2)
        return;
    tmp = a->top;
    a->top = a->top->next;
    tmp->next = NULL;
    last = a->top;
    while (last->next)
        last = last->next;
    last->next = tmp;
    write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
    t_node	*tmp;
	t_node	*last;

    if (b->size < 2)
        return;
    tmp = b->top;
    b->top = b->top->next;
    tmp->next = NULL;
    last = b->top;
    while (last->next)
        last = last->next;
    last->next = tmp;
    write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
    write(1, "rr\n", 3);
}

void	rra(t_stack *a)
{
    t_node	*prev;
	t_node	*last;

    if (a->size < 2)
        return;
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
    write(1, "rra\n", 4);
}

void rrb(t_stack *b)
{
    t_node *prev;
	t_node *last;

    if (b->size < 2)
        return;
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
    write(1, "rrb\n", 4);
}

void rrr(t_stack *a, t_stack *b)
{
    rra(a);
    rrb(b);
    write(1, "rrr\n", 4);
}

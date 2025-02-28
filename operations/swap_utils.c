/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:21:17 by halzamma          #+#    #+#             */
/*   Updated: 2025/02/25 23:21:17 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack *a)
{
    t_node *tmp;

    if (a->size < 2)
        return;
    tmp = a->top->next;
    a->top->next = tmp->next;
    tmp->next = a->top;
    a->top = tmp;
    write(1, "sa\n", 3);
}

void sb(t_stack *b)
{
    t_node *tmp;

    if (b->size < 2)
        return;
    tmp = b->top->next;
    b->top->next = tmp->next;
    tmp->next = b->top;
    b->top = tmp;
    write(1, "sb\n", 3);
}

void ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
    write(1, "ss\n", 3);
}
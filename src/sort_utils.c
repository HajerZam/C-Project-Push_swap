/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:11:04 by halzamma          #+#    #+#             */
/*   Updated: 2025/03/05 15:11:04 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_min_index(t_stack *a)
{
    int		min;
    t_node	*tmp;  // Use t_node instead of t_stack

    tmp = a->top;  // Start from the top of the stack
    min = tmp->nb;
    while (tmp)
    {
        if (tmp->nb < min)
            min = tmp->nb;
        tmp = tmp->next;
    }
    return (min);
}

int	get_max_bits(t_stack *a)
{
    int		max_bits;
    int		max;
    t_node	*tmp;  // Use t_node instead of t_stack

    if (!a || !a->top) // Check if stack is empty
        return (0);

    tmp = a->top;  // Start from the top node
    max = tmp->nb;
    while (tmp)
    {
        if (tmp->nb > max)
            max = tmp->nb;
        tmp = tmp->next;
    }
    max_bits = 0;
    while (max)
    {
        max_bits++;
        max /= 10;
    }
    return (max_bits);
}

void	move_to_top(t_stack *a, int min_index)
{
    int		i;
    t_node	*tmp;  // Use t_node instead of t_stack

    if (!a || !a->top) // Check if stack is empty
        return;

    i = 0;
    tmp = a->top;
    while (tmp && tmp->nb != min_index) // Iterate until min_index is found
    {
        tmp = tmp->next;
        i++;
    }
    if (i < stack_size(a) / 2)
        while (a->top->nb != min_index)
            ra(a);
    else
        while (a->top->nb != min_index)
            rra(a);
}
int stack_is_empty(t_stack *stack)
{
    return (stack == NULL || stack->top == NULL);
}

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
	t_stack	*tmp;

	tmp = a;
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
	t_stack	*tmp;

	tmp = a;
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

int	stack_is_empty(t_stack *stack)
{
	if (!stack)
		return (1);
	return (0);
}

void	move_to_top(t_stack *a, int min_index)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = a;
	while (tmp->nb != min_index)
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

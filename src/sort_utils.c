/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:11:04 by halzamma          #+#    #+#             */
/*   Updated: 2025/03/24 13:06:06 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_min_index(t_stack *a)
{
	int		min_value;
	int		min_index;
	int		i;
	t_node	*current;

	if (!a || !a->top)
		return (-1);
	min_value = a->top->nb;
	min_index = 0;
	i = 0;
	current = a->top;
	while (current)
	{
		if (current->nb < min_value)
		{
			min_value = current->nb;
			min_index = i;
		}
		current = current->next;
		i++;
	}
	return (min_index);
}

void	move_min_to_top(t_stack *a, int min_index)
{
	int	size;

	if (min_index == -1)
		return ;
	size = a->size;
	if (min_index <= size / 2)
	{
		while (min_index-- > 0)
			ra(a);
	}
	else
	{
		min_index = size - min_index;
		while (min_index-- > 0)
			rra(a);
	}
}

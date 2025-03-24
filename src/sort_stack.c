/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:19:08 by halzamma          #+#    #+#             */
/*   Updated: 2025/03/24 13:04:37 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/ft_printf.h"

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->nb;
	second = a->top->next->nb;
	third = a->top->next->next->nb;
	if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first > second && second < third && first < third)
		sa(a);
	else if (first < second && second > third && first > third)
		rra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	min_index;

	min_index = find_min_index(a);
	move_min_to_top(a, min_index);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min_index;

	min_index = find_min_index(a);
	move_min_to_top(a, min_index);
	pb(a, b);
	min_index = find_min_index(a);
	move_min_to_top(a, min_index);
	pb(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

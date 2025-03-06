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

#include "../include/push_swap.h"
#include "../include/ft_printf.h"

void	pa(t_stack *a, t_stack *b)
{
	int	value;

	if (b->size < 1)
		return ;
	value = pop(b);
	push(a, value);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	int	value;

	if (a->size < 1)
		return ;
	value = pop(a);
	push(b, value);
	ft_printf("pb\n");
}

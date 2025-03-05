/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:02:34 by halzamma          #+#    #+#             */
/*   Updated: 2025/03/05 13:02:34 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

void	push_to_stack(t_stack *stack, int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return ;
	new->value = value;
	new->next = stack->top;
	stack->top = new;
	stack->size++;
}

void	fill_stack(t_stack *a, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		push_to_stack(a, ft_atoi(argv[i]));
		i++;
	}
}

t_stack	*init_stack(void)
{
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:02:34 by halzamma          #+#    #+#             */
/*   Updated: 2025/03/07 17:25:23 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

void push_to_stack(t_stack *stack, int value)
{
	t_node *new;
	t_node *current;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return ;
	new->nb = value;
	new->next = NULL;
	if (stack->top == NULL)
	{
		stack->top = new;
	}
	else
	{
		current = stack->top;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new;
	}
	stack->size++;
}

void	fill_stack(t_stack *a, char *argv[])
{
	int	i;
	int value;

	i = 1;
	while (argv[i])
	{
		value = ft_atoi(argv[i]);
		if (value >= 2147483647 || value <= -2147483648)
			exit(1);
		push_to_stack(a, value);
		i++;
	}
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

int	stack_size(t_stack *stack)
{
	return (stack->size);
}

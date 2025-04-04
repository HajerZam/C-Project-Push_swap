/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:02:34 by halzamma          #+#    #+#             */
/*   Updated: 2025/03/24 15:21:43 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

void	push_to_stack(t_stack *stack, int value)
{
	t_node	*new;
	t_node	*current;

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

void	fill_values(t_stack *a, char *argv[])
{
	int		i;
	long	value;

	i = 1;
	while (argv[i])
	{
		value = ft_atol(argv[i]);
		if (value > 2147483647 || value < -2147483648)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		push_to_stack(a, value);
		i++;
	}
}

void	assign_indexes(t_stack *a)
{
	int		*arr;
	int		size;
	t_node	*tmp;

	size = a->size;
	arr = stack_to_array(a);
	sort_array(arr, size);
	tmp = a->top;
	while (tmp)
	{
		tmp->nb = get_index(arr, tmp->nb, size);
		tmp = tmp->next;
	}
	free(arr);
}

void	fill_stack(t_stack *a, char *argv[])
{
	fill_values(a, argv);
	assign_indexes(a);
}

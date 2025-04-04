/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:15:38 by halzamma          #+#    #+#             */
/*   Updated: 2025/04/02 14:39:26 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

void	initialize_stacks(t_stack **a, t_stack **b)
{
	*a = init_stack();
	*b = init_stack();
}

void	sort_stacks(t_stack *a, t_stack *b)
{
	if (is_sorted(a) || a->size == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size <= 6)
		sort_five(a, b);
	else if (a->size <= 100)
		radix_sort(a, b, 5);
	else
		radix_sort(a, b, 11);
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
	free(stack);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	
	if (is_valid(argc, argv) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	a = init_stack();
	b = init_stack();
	if (argc == 2)
	{
		fill_stack_string(a, argv[1]);
	}
	else
		fill_stack(a, argv);
	sort_stacks(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}

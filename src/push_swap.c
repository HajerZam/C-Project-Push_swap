/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:15:38 by halzamma          #+#    #+#             */
/*   Updated: 2025/03/24 12:58:50 by halzamma         ###   ########.fr       */
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
	if (is_sorted(a))
		return ;
	if (a->size == 2)
	{
		if (a->top->nb > a->top->next->nb)
			sa(a);
	}
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	if (!stack || !stack->top)
		return ;
	while (stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
	free(stack);
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	ft_printf("Stack (size = %d):\n", stack->size);
	while (current != NULL)
	{
		ft_printf("%d -> ", current->nb);
		current = current->next;
	}
	ft_printf("NULL\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2 || !check_args(argc, argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	ft_printf("Args checked!\n");
	a = init_stack();
	b = init_stack();
	printf("Stack initialized!\n");
	fill_stack(a, argv);
	printf("Stack filled!\n %d\n", a->size);
	print_stack(a);
	sort_stacks(a, b);
	printf("Stack sorted!\n");
	print_stack(a);
	print_stack(b);
	free_stack(a);
	printf("Stack freed!\n");
	free_stack(b);
	printf("Stack freed!\n");
	return (0);
}

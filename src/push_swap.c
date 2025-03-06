/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:15:38 by halzamma          #+#    #+#             */
/*   Updated: 2025/02/28 15:15:38 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

void	initialize_stacks(t_stack **a, t_stack **b)
{
	*a = init_stack();
	*b = init_stack();
}

void	sort_stacks(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	if (size <= 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else if (size <= 100)
		insertion_sort(a, b);
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


int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	initialize_stacks(&a, &b);
	if (!a || !b)
	{
		printf("Stack initialization failed!\n");
		return (0);
	}
	if (argc < 2 || !check_valid(argc, argv))
	{
		printf("Invalid input!1\n");
		return (0);
	}
	fill_stack(a, argv);
	if (!check_args(argv) || check_sorted(a))
	{
		printf("Invalid input!2\n");
		return (0);
	}
	printf("Stack initialized!\n");
	sort_stacks(a, b);
	printf("Stack sorted!\n");
	free_stack(a);
	printf("Stack freed!\n");
	free_stack(b);
	printf("Stack freed!\n");
	return (0);
}

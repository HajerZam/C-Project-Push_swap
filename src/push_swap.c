/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:15:38 by halzamma          #+#    #+#             */
/*   Updated: 2025/03/10 14:27:35 by halzamma         ###   ########.fr       */
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
	if (a->size == 3)
        sort_three(a);
    else if (a->size == 5)
        sort_five(a, b);
    else if (a->size <= 100)
        greedy_sort(a, b);
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

void print_stack(t_stack *stack)
{
    t_node *current = stack->top;
    printf("Stack (size = %d):\n", stack->size);
    while (current != NULL)
    {
        printf("%d -> ", current->nb);  // Print the current node's nb
        current = current->next;
    }
    printf("NULL\n");  // End of stack
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

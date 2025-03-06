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

#include "./include/push_swap.h"
#include "./include/libft.h"

void	initialize_stacks(t_stack **a, t_stack **b)
{
	*a = init_stack();
	*b = init_stack();
}

int	valid_input(int argc, char **argv, t_stack *a)
{
	if (argc < 2 || !check_valid(argc, argv))
		return (0);
	fill_stack(a, argv);
	if (!check_args(argv, a) || check_sorted(a))
		return (0);
	return (1);
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	initialize_stacks(&a, &b);
	if (!a || !b || !valid_input(argc, argv, a))
		return (0);
	sort_stacks(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}

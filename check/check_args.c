/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:39:04 by halzamma          #+#    #+#             */
/*   Updated: 2025/02/28 12:39:04 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

int	check_valid(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				ft_printf("Error\n");
				return (0);
			}
			j++;
		}
		if (ft_atoi(argv[i]) >= 2147483647 || ft_atoi(argv[i]) <= -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	check_double(int nb, t_stack *a)
{
	t_node	*tmp;

	if (!a || !a->top)
		return (1);
	tmp = a->top;
	while (tmp)
	{
		if (tmp->nb == nb)
		{
			ft_printf("Error\n");
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	check_args(char **argv, t_stack *a)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		if (ft_atoi(argv[i]) >= 2147483647 || ft_atoi(argv[i]) <= -2147483648)
			return (0);
		if (check_double(ft_atoi(argv[i]), a) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_sorted(t_stack *a)
{
	t_node *tmp;

	if (!a || !a->top)
		return (1);
	tmp = a->top;
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

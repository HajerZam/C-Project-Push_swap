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
				ft_printf("Error1\n"); // error
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

int	check_double(char *argv[])
{
	int	i;
	int	j;

	i = 1;
    while (argv[i])
    {
		j = i + 1;
        while (argv[j])
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
            {
                printf("Error2\n i = %s\n j = %s\n",argv[i],argv[j]);  // Debug print
                return (0);
            }
			j++;
        }
		i++;
    }
    return (1);
}

int	check_args(char **argv)
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
		if (check_double(argv) == 0)
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

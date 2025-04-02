/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:47:24 by halzamma          #+#    #+#             */
/*   Updated: 2025/03/15 11:47:24 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

int	is_sorted(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp && tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_valid(int argc, char **argv)
{
	if (argc < 2)
		return (0); 
	else if (argc == 2)
	{
		if (check_string(argv[1]) == 0)
			return (0);
	}
	else if (argc > 2)
	{	
		if (check_args(argc, argv) == 0)
			return (0);
	}
	return (1);
}

int check_string(char *str) 
{
    int i;
    int has_digit;

	i = 0;
	has_digit = 0;
    while (str[i])
	{
        if (str[i] == '-')
		{
            if (str[i + 1] && !ft_isdigit(str[i + 1]))
                return (0);
            i++;
        }
        if (ft_isdigit(str[i]))
            has_digit = 1;
        else if (str[i] != ' ')
            return 0;
        i++;
    }
    return (has_digit);
}

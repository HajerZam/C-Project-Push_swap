/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:37:58 by halzamma          #+#    #+#             */
/*   Updated: 2025/04/02 12:37:58 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"

void	fill_stack_string(t_stack *a, char *arg)
{
	char	**args;
	int		i;

	args = ft_split(arg, ' ');
	if (!args)
		return;
	i = 0;
	while (args[i])
	{
		push_to_stack(a, ft_atoi(args[i]));
		free(args[i]);
		i++;
	}
	free(args);
}

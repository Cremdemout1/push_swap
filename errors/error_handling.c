/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:05:03 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/30 13:48:21 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_str_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	arg_validity(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (!(digit(array[i][j]) || array[i][j] == '+'
					|| array[i][j] == '-'))
				return (1);
			if ((array[i][j] == '+' || array[i][j] == '-') && !digit(array[i][j
					+ 1]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	duplicate_checker(t_stack **stack)
{
	t_stack	*current;
	t_stack	*compared;

	if (!stack)
		return (0);
	current = *stack;
	while (current)
	{
		compared = current->next;
		while (compared)
		{
			if (current->content == compared->content)
				return (1);
			compared = compared->next;
		}
		current = current->next;
	}
	return (0);
}

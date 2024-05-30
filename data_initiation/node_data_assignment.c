/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_data_assignment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:42:08 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/30 14:08:36 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	assign_index_and_median(t_stack **stack)
{
	int		index;
	int		median;
	t_stack	*current;

	index = 0;
	median = get_median(stack);
	current = *stack;
	while (current)
	{
		current->index = index;
		if (current->index <= median)
			current->median_value = 0;
		else
			current->median_value = 1;
		index++;
		current = current->next;
	}
}

void	assign_target(t_stack **stack_a, t_stack **stack_b)
{
	int		bff;
	t_stack	*target;
	t_stack	*current_a;
	t_stack	*current_b;

	current_b = *stack_b;
	while (current_b)
	{
		bff = INT_MAX;
		current_a = *stack_a;
		while (current_a)
		{
			if (current_a->content < bff
				&& current_a->content > current_b->content)
			{
				bff = current_a->content;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (bff == INT_MAX)
			target = find_smallest(stack_a);
		current_b->target = target;
		current_b = current_b->next;
	}
}

void	assign_cost(t_stack **stack_b, int len_a, int len_b)
{
	t_stack	*current_b;

	current_b = *stack_b;
	while (current_b)
	{
		if (current_b->median_value == 0
			&& current_b->target->median_value == 0)
			current_b->cost = current_b->index + current_b->target->index;
		if (current_b->median_value == 0
			&& current_b->target->median_value == 1)
			current_b->cost = current_b->index + (len_a
					- current_b->target->index);
		if (current_b->median_value == 1
			&& current_b->target->median_value == 0)
			current_b->cost = (len_b - current_b->index)
				+ current_b->target->index;
		if (current_b->median_value == 1
			&& current_b->target->median_value == 1)
			current_b->cost = (len_b - current_b->index) + (len_a
					- current_b->target->index);
		current_b = current_b->next;
	}
}

// void	assign_cost(t_stack **stack_a, t_stack **stack_b)
// {
// 	int len_a;
// 	int len_b;
// 	t_stack *current;

// 	current = *stack_b;
// 	len_a = length
// }

void	assign_cheapest(t_stack **stack_b)
{
	int		i;
	int		cost;
	t_stack	*current;

	i = 0;
	cost = INT_MAX;
	current = *stack_b;
	while (current)
	{
		if (current->cost < cost)
		{
			i = current->index;
			cost = current->cost;
		}
		current->cheapest = 0;
		current = current->next;
	}
	current = *stack_b;
	while (current->index != i)
	{
		current = current->next;
	}
	current->cheapest = 1;
}

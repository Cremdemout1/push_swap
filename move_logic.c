/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:07:04 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/30 13:47:49 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// FOLLOW SAME LOGIC AS FOR TH COST CALCULATION AND ASSIGNMENT.
// THIS WILL ALLOW ME TO USE RR AND RRR TO SAVE MOVES.

void	both_under_median_value(t_stack **stack_a, t_stack **stack_b,
		t_stack *for_the_top)
{
	while (*stack_a != for_the_top->target && *stack_b != for_the_top)
		rr(stack_a, stack_b);
	assign_index_and_median(stack_a);
	assign_index_and_median(stack_b);
}

void	both_over_median_value(t_stack **stack_a, t_stack **stack_b,
		t_stack *for_the_top)
{
	while (*stack_a != for_the_top->target && *stack_b != for_the_top)
		rrr(stack_a, stack_b);
	assign_index_and_median(stack_a);
	assign_index_and_median(stack_b);
}

static void	rotation_end(t_stack **stack, t_stack *for_the_top, char name)
{
	while (*stack != for_the_top)
	{
		if (name == 'a')
		{
			if (for_the_top->median_value == 1)
				rra(stack);
			else
				ra(stack);
		}
		else if (name == 'b')
		{
			if (for_the_top->median_value == 1)
				rrb(stack);
			else
				rb(stack);
		}
	}
}

void	all_moves(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = *stack_b;
	while (cheapest)
	{
		if (cheapest->cheapest == 1)
			break ;
		else
			cheapest = cheapest->next;
	}
	if (cheapest->median_value == 0 && cheapest->target->median_value == 0)
		both_under_median_value(stack_a, stack_b, cheapest);
	else if (cheapest->median_value == 1 && cheapest->target->median_value == 1)
		both_over_median_value(stack_a, stack_b, cheapest);
	rotation_end(stack_b, cheapest, 'b');
	rotation_end(stack_a, cheapest->target, 'a');
	pa(stack_a, stack_b);
}

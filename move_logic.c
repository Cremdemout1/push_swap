/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:07:04 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/29 18:25:30 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// FOLLOW SAME LOGIC AS FOR TH COST CALCULATION AND ASSIGNMENT.

// THIS WILL ALLOW YOU TO USE RR AND RRR TO SAVE MOVES.

void both_under_median_value(t_stack **stack_a, t_stack **stack_b, t_stack *for_the_top)
{
    t_stack *target;

    target = for_the_top->target;
    while ((*stack_a != target) && (*stack_b != for_the_top))
        rr(stack_a, stack_b);
    if (*stack_a == target)
        while (*stack_b != for_the_top)
            rb(stack_b);
    else if (*stack_b == for_the_top)
        while (*stack_a != target)
            ra(stack_a);
    //assign_node_index(stack_a, stack_b);
}

void both_over_median_value(t_stack **stack_a, t_stack **stack_b, t_stack *for_the_top)
{
    t_stack *target;

    target = for_the_top->target;
    while ((*stack_a != target) && (*stack_b != for_the_top))
        rrr(stack_a, stack_b);
    if (*stack_a == target)
        while (*stack_b != for_the_top)
            rrb(stack_b);
    else if (*stack_b == for_the_top)
        while (*stack_a != target)
            rra(stack_a);
    //assign_node_index(stack_a, stack_b);
}

void not_on_same_side(t_stack **stack_a, t_stack **stack_b, t_stack *for_the_top)
{
    t_stack *target;

    target = for_the_top->target;
    if (for_the_top->median_value == 1 && target->median_value == 0)
    {
        while (*stack_b != for_the_top)
            rb(stack_b);
        while (*stack_a != target)
            rra(stack_a);
    }
    else if (for_the_top->median_value == 0 && target->median_value == 1)
    {
        while (*stack_b != for_the_top)
            rrb(stack_b);
        while (*stack_a != target)
            ra(stack_a);
    }
    //assign_node_index(stack_a, stack_b);
}

void all_moves(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *current_b;
    t_stack *last;

    current_b = *stack_b;
    last = last_index(stack_a);
    while (current_b)
    {
        if (current_b->cheapest != 1)
            current_b = current_b->next;
        else
            break;
    }
    if (current_b->target == last)
    {
        pa(stack_a, stack_b);
        ra(stack_a);
    }
    if (current_b->median_value == 0 && current_b->target->median_value == 0)
        both_under_median_value(stack_a, stack_b, current_b);
    else if (current_b->median_value == 1 && current_b->target->median_value == 1)
        both_over_median_value(stack_a, stack_b, current_b);
    else
        not_on_same_side(stack_a, stack_b, current_b);
    pa(stack_a, stack_b);
}
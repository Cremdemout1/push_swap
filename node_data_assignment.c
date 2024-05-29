/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_data_assignment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:42:08 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/29 18:27:59 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    assign_node_index(t_stack **stack_a, t_stack **stack_b)
{
    int index;
    t_stack *curr_a;
    t_stack *curr_b;
    
    index = 0;
    curr_a = *stack_a;
    curr_b = *stack_b;
    while (curr_a)
    {
        curr_a->index = index;
        curr_a = curr_a->next;
        index++;
    }
    index = 0;
    while (curr_b)
    {
        curr_b->index = index;
        curr_b = curr_b->next;
        index++;
    }
}

void    assign_target(t_stack **stack_a, t_stack **stack_b)
{
    int bff;
    t_stack *target;
    t_stack *current_a;
    t_stack *current_b;
    
    current_b = *stack_b;
    while (current_b)
    {
        bff = INT_MAX;
        current_a = *stack_a;
        while (current_a)
        {
            if (current_a->content < bff && current_a->content > (current_b->content))
            {
                target = current_a;
                bff = current_a->content;
            }
            current_a = current_a->next;
        }
        if (bff == INT_MAX)
            target = find_smallest(stack_a);
        current_b->target = target;
        current_b = current_b->next;
    }
}

void    assign_median_up_or_down(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *current_a;
    t_stack *current_b;

    current_a = *stack_a;
    current_b = *stack_b;
    while (current_a)
    {
        if (current_a->index < get_median(stack_a))
            current_a->median_value = 0;
        else
            current_a->median_value = 1;
        current_a = current_a->next;
    }
    while (current_b)
    {
        if (current_b->index < get_median(stack_b))
            current_b->median_value = 0;
        else
            current_b->median_value = 1;
        current_b = current_b->next;
    }
}

void    assign_cost(t_stack **stack_a, t_stack **stack_b)
{
    int len_a;
    int len_b;
    t_stack *current_b;
    
    current_b = *stack_b;
    while(current_b)
    {
        len_a = length_of_list(stack_a);
        len_b = length_of_list(stack_b);
        if (current_b->median_value == 0 && current_b->target->median_value == 0)
            current_b->cost = current_b->index + current_b->target->index;
        if (current_b->median_value == 0 && current_b->target->median_value == 1)
            current_b->cost = current_b->index + (len_a - current_b->target->index);
        if (current_b->median_value == 1 && current_b->target->median_value == 0)
            current_b->cost = (len_b - current_b->index) + current_b->target->index;
        if (current_b->median_value == 1 && current_b->target->median_value == 1)
            current_b->cost = (len_b - current_b->index) + (len_a - current_b->target->index);
        current_b = current_b->next;
    }
    
}

void    assign_cheapest(t_stack **stack_b)
{
    int i;
    int cost;
    t_stack *current;

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
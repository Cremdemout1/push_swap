/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_assignment_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:43:28 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/29 11:52:59 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack     *find_smallest(t_stack **stack_a)
{
    t_stack *current;
    int small;
    t_stack *target;

    small = INT_MAX;
    target = NULL;
    current = *stack_a;
    while (current)
    {
        if (current->content < small)
        {
            small = current->content;
            target = current;
        }
        current = current->next;
    }
    return (target);
}

int    get_median(t_stack **stack)
{
    int i;
    int median;
    t_stack *current;

    i = 0;
    current = *stack;
    while (current)
    {
        i++;
        current = current->next;
    }
    if (i % 2 == 0)
        median = i / 2 - 1;
    else
        median = i / 2;
    return(median);
}

void    assign_data(t_stack **stack_a, t_stack **stack_b)
{
    assign_node_index(stack_a, stack_b);
    assign_target(stack_a, stack_b);
    assign_median_up_or_down(stack_a, stack_b);
    assign_cost(stack_a, stack_b);
    assign_cheapest(stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:31:52 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/27 14:16:46 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     move_count(t_stack **stack, t_stack **stack_b)
{
    int total;
    int lowest_cost;
    int up;
    int down;

    total = node_amount(stack);
    lowest_cost = find_lowest_cost(stack_b);
    up = 0;
    down = 0;
    while (up < lowest_cost)
        up++;
    down = total - up;
    if (up < down)
        return (1);
    else
        return (0);
}

int     node_amount(t_stack **stack)
{
    int i;
    t_stack *current;
    
    if (!stack && !*stack)
    {
        clear_list(stack);
        return (0);
    }
    i = 0;
    current = *stack;
    while (current != NULL)
    {
        i++;
        current = current->next;
    }
    return (i);
}


void    move_lowest_b_to_top(t_stack **stack_a, t_stack **stack_b, int lowest)
{
    int total;
    int iterator;

    iterator = 0;
    total = node_amount(stack_a);
    if (move_count(stack_b, stack_b) == 1)
    {
        iterator = lowest;
        while (iterator > 0)
        {
            rb(stack_b);
            iterator--;
        }
    }
    else
    {
        iterator = total - lowest;
        while (iterator > 0)
        {
            rrb(stack_b);
            iterator--;
        }
    }
}

void    move_head_of_a_to_target(t_stack **stack_a, t_stack **stack_b)
{
    int i;
    int up;
    int down;
    int total;

    i = 0;
    up = 0;
    down = 0;
    //printf("bff = %d", find_bff(stack_a, *stack_b));
    up = find_bff(stack_a, *stack_b);
    total = node_amount(stack_a);
    down = total - up;
    if (up < down)
    {
        while (i < up)
        {
            rra(stack_a);
            i++;
        }
        pa(stack_a, stack_b);
        while (i > 0)
        {
            ra(stack_a);
            i--;
        }
    }
    else
    {
        while (i < down)
        {
            ra(stack_a);
            i++;
        }
        pa(stack_a, stack_b);
        while (i > 0)
        {
            rra(stack_a);
            i--;
        }
    }
}
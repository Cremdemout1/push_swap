/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:31:52 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/24 09:49:05 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int    find_smallest(t_stack **stack)
// {
//     t_stack *current;
//     int node_placement;
//     int smallest_index;
//     int smallest_value;

//     current = *stack;
//     node_placement = 0;
//     smallest_value = INT_MAX;
//     smallest_index = 0;
//     while(current != NULL)
//     {
//         if (current->content < smallest_value)
//         {
//             smallest_value = current->content;
//             smallest_index = node_placement;
//         }
//         node_placement++;
//         current = current->next;
//     }
//     return(smallest_index);
// }
//CREATE FUNCTION THAT calculates moves from smallest node to first node of stack_b.
//when the smallest node reaches the top, pa and rra.

// int     move_count(t_stack **stack)             //fix this to not use find_smallest
// {
//     int lowest;
//     int up;
//     int down;
//     int total_nodes;

//     down = 0;
//     up = find_lowest_cost();
//     total_nodes = node_amount(stack);
//     down = total_nodes - up;
//     if (up < down)
//         return(UP);
//     else
//         return (DOWN);
// }
// void    move_to_top(t_stack **stack_b, int *count)
// {
//     int smallest;
//     int total_nodes;
//     int counter;
    
//     counter = 0;
//     smallest = find_smallest(stack_b);
//     total_nodes = node_amount(stack_b);
//     if(move_count(stack_b) == UP)
//     {
//         counter = smallest;
//         while(counter > 0)
//         {
//             rb(stack_b, count);
//             counter--;
//         }
//     }
//     else
//     {
//         counter = total_nodes - smallest;
//         while (counter > 0)
//         {
//             rrb(stack_b, count);
//             counter--;
//         }
//     }
// }
int     move_count(t_stack **stack, t_stack **stack_b)
{
    int total;
    int up;
    int down;

    total = node_amount(stack);
    up = 0;
    down = 0;
    while (up < find_lowest_cost(stack_b))
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
        clear_list(stack);
    i = 0;
    current = *stack;
    while (current != NULL)
    {
        i++;
        current = current->next;
    }
    return (i);
}


void    move_lowest_b_to_top(t_stack **stack_a, t_stack **stack_b, int lowest, int *count)
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
            rb(stack_b, count);
            iterator--;
        }
    }
    else
    {
        iterator = total - lowest;
        while (iterator > 0)
        {
            rrb(stack_b, count);
            iterator--;
        }
    }
}

void    move_head_of_a_to_target(t_stack **stack_a, t_stack **stack_b, int *count)
{
    int i;
    int up;
    int down;
    int total;

    i = 0;
    up = 0;
    down = 0;
    //printf("bff = %d", find_bff(stack_a, *stack_b));
    while (up < find_bff(stack_a, *stack_b))
        up++;
    total = node_amount(stack_a);
    down = total - up;
    if (up < down)
    {
        while (i < up)
        {
            rra(stack_a, count);
            i++;
        }
        pa(stack_a, stack_b, count);
        while (i > 0)
        {
            ra(stack_a, count);
            i--;
        }
    }
    else
    {
        while (i < down)
        {
            ra(stack_a, count);
            i++;
        }
        pa(stack_a, stack_b, count);
        while (i > 0)
        {
            rra(stack_a, count);
            i--;
        }
    }
}
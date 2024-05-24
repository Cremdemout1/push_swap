/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:48:35 by yohan             #+#    #+#             */
/*   Updated: 2024/05/24 09:59:37 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sorted_check(t_stack **stack_a)
{
    
    if (is_it_sorted(stack_a) == SORTED)
    {
        write(1, "list already sorted\n", 21);
        clear_list(stack_a);
        exit(1);
    }
}

int    is_it_sorted(t_stack **stack)
{
    t_stack *current;

    current = *stack;
    if(!current)
        return(UNSORTED);
    while (current->next)
    {
        if(current->next->content < current->content)
            return(UNSORTED);
        current = current->next;
    }
    return (SORTED);
}

void    sort_three(t_stack **stack, int *count)
{
    int first = (*stack)->content;
    int second = (*stack)->next->content;
    int third = (*stack)->next->next->content;
    
    if (second > third && third > first)
    {
        rra(stack, count);
        sa(stack, count);
    }
    else if (first > second && first < third)
        sa(stack, count);
    else if (first < second && first > third)
        rra(stack, count);
    else if (first > second && second > third)
    {
        ra(stack, count);
        sa(stack, count);
    }
    if (first > third && second < third)
        ra(stack, count);
}

//make sure that only things under the average of stacka are moved to stackb or ra.


// void    selective_init_push(t_stack **stack_a, t_stack **stack_b, int *count)
// {
//     t_stack *current;
//     int average;
//     int num_nodes;
    
//     num_nodes = node_amount(stack_a);
//     while(num_nodes > 3)
//     {
//         average = 0;
//         current = *stack_a;
//         while (current)
//         {
//             average += current->content;
//             current = current->next;
//         }
//         average /= num_nodes;
//         current = *stack_a;
//         if (current && current->content < average)
//             pb(stack_a, stack_b, count);
//         else
//             ra(stack_a, count);
//         num_nodes = node_amount(stack_a);
//     }
// }

void    selective_init_push(t_stack **stack_a, t_stack **stack_b, int *count)
{
    t_stack *current;
    int median;
    int num_nodes;
    
    num_nodes = node_amount(stack_a);
    while(num_nodes > 3)
    {
        median = find_median(stack_a, num_nodes);
        current = *stack_a;
        if (current && current->content < median)
            pb(stack_a, stack_b, count);
        else
            ra(stack_a, count);
        num_nodes = node_amount(stack_a);
    }
}
void    new_sort(t_stack **stack_a, t_stack **stack_b, int *count)
{
    int i;
    int low_cost;
    t_stack *current_b;
    t_stack *lowest_cost;

    i = 0;
    selective_init_push(stack_a, stack_b, count);
    sort_three(stack_a, count);
    current_b  = *stack_b;
    lowest_cost = *stack_b;
    while (current_b)
    {
        cost_assign(stack_a, stack_b);
        low_cost = find_lowest_cost(stack_b);
        while (i < low_cost && lowest_cost)
        {
            lowest_cost = lowest_cost->next;                        //finds lowest cost in stack_b
            i++;
        }
        move_lowest_b_to_top(stack_a, stack_b, low_cost, count);//moves lowest cost to top of stack_b
        move_head_of_a_to_target(stack_a, stack_b, count);
        current_b = current_b->next;        //move_inside_a ft tells me how many times I need to ra or rra but not if I should ra pr rra. fix pls
    }
}

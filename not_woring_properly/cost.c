/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:36:41 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/27 13:41:52 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//function that finds the node which contains the next biggest integer after stack_b head
int    find_bff(t_stack **stack_a, t_stack *node)
{
    if (!node)
        return (-1);
    int b_head;
    int bff;
    int index;
    int node_iter;
    t_stack *current;
    
    b_head = node->content;
    bff = INT_MAX;
    index = -1;
    node_iter = 0;
    current = *stack_a;
    while (current)
    {
        if (current->content < bff && current->content > b_head)
        {
            index = node_iter;
            bff = current->content;
        }
        current = current->next;
        node_iter++;
    }
    return(index);
}

int     move_inside_a(t_stack **stack_a, t_stack *current)
{
    int up;
    int down;
    int total_nodes;

    down = 0;
    up = 0;
    up = find_bff(stack_a, current);
    total_nodes = node_amount(stack_a);
    down = total_nodes - up;
    if (up < down)
        return(up);
    else
        return (down);
}

int move_inside_b(t_stack **stack_b, t_stack *current)
{
    int up;
    int down;
    int total;
    t_stack *start;

    up = 0;
    down = 0;
    total = node_amount(stack_b);
    start = current;
    while (start)
    {
        up++;
        start = start->next;
    }
    down = total - up;
    if (up < down)
        return (up);
    else
        return (down);
}

//function that finds best path to join "best friend" cost = moves to bring node to top of stack_b + put it into stack_a
void     cost_assign(t_stack **stack_a, t_stack **stack_b)
{
    int moves;
    t_stack *current;

    moves = 0;
    current = *stack_b;
    if (find_bff(stack_a, current) == -1)
        clear_list(stack_b);
    while (current)
    {
        moves = (move_inside_a(stack_a, current) * 2) + move_inside_b(stack_b, current); //number of moves = rotating and reverse rotating after putting node + putting b to the top 
        current->cost = moves;
        current = current->next;
    }
}

int     find_lowest_cost(t_stack **stack_b)
{
    int least;
    int i;
    int index;
    t_stack *current;

    least = INT_MAX;
    i = 0;
    index = -1;
    current = *stack_b;
    while (current)
    {
        if (current->cost < least)
        {
            index = i;
            least = current->cost;
        }
        current = current->next;
        i++;
    }
    return (least);
}
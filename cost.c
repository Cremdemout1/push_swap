/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:36:41 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/23 23:19:47 by yohan            ###   ########.fr       */
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
    int node_iter;
    t_stack *current;
    
    b_head = node->content;
    bff = INT_MAX;
    node_iter = 0;
    current = *stack_a;
    while (current)
    {
        if (current->content < bff && current->content > b_head)
            bff = node_iter;
        current = current->next;
        node_iter++;
    }
    
    if (bff == INT_MAX)
        return(0);
    return(bff);
}

int     move_inside_a(t_stack **stack_a, t_stack *current)
{
    int up;
    int down;
    int total_nodes;

    down = 0;
    up = 0;
    while (up < find_bff(stack_a, current))
        up++;
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
    down = total - up - 1;
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
    t_stack *current;

    least = INT_MAX;
    i = 0;
    current = *stack_b;
    while (current)
    {
        if (!current->prev || current->cost < current->prev->cost)
            least = i;
        current = current->next;
        i++;
    }
    return (least);
}
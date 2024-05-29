/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:35:48 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/29 18:28:48 by ycantin          ###   ########.fr       */
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

void    sort_three(t_stack **stack)
{
    int first = (*stack)->content;
    int second = (*stack)->next->content;
    int third = (*stack)->next->next->content;
    
    if (second > third && third > first)
    {
        rra(stack);
        sa(stack);
    }
    else if (first > second && first < third)
        sa(stack);
    else if (first < second && first > third)
        rra(stack);
    else if (first > second && second > third)
    {
        ra(stack);
        sa(stack);
    }
    if (first > third && second < third)
        ra(stack);
    
}

void    sort(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *current;
    t_stack *smallest;
    int i;

    i = 0;
    current = *stack_a;
    while (current)
    {
        i++;
        current = current->next;
    }
    while (i > 3)
    {
        pb(stack_a, stack_b);
        i--;
    }
    sort_three(stack_a);
    while(*stack_b)
    {
        assign_data(stack_a, stack_b);
        all_moves(stack_a, stack_b);
    }
    assign_node_index(stack_a, stack_b);
    assign_median_up_or_down(stack_a, stack_b);
    smallest = find_smallest(stack_a);
    	if ((*stack_a)->median_value == 0)
		while (*stack_a != smallest)
			ra(stack_a);
	else
		while (*stack_a != smallest)
			rra(stack_a);
}
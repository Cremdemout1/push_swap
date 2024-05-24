/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:39:02 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/20 16:00:05 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    rotate(t_stack **stack)
{
    t_stack *last;
    t_stack *next;

    if (!*stack)
        return ;
    last = *stack;
    while (last->next)
        last = last->next;
    next = (*stack)->next;
    (*stack)->prev = last; //initiating circular lst
    last->next = *stack; 
    (*stack)->next = NULL; //reinitialize node pointers
    next->prev = NULL;
    *stack = next; //next is now head
}

void    ra(t_stack   **stack_a, int *count)
{
    write(1, "ra\n", 3);
    rotate(stack_a);
    (*count)++;
}

void    rb(t_stack   **stack_b, int *count)
{
    write(1, "rb\n", 3);
    rotate(stack_b);
    (*count)++;
}

void    rr(t_stack   **stack_a, t_stack   **stack_b, int *count)
{
    write(1, "rr\n", 3);
    rotate(stack_a);
    rotate(stack_b);
    (*count) += 2;
}
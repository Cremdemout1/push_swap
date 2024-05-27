/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:56:02 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/27 14:37:36 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void rev_rotate(t_stack **stack)
// {
//     t_stack *last;

//     if (!*stack || !(*stack)->next)
//         return ;
//     last = ft_lstlast(*stack);
//     last->next = *stack;// creates circular linked list 
//     (*stack)->prev = last;
//     last->prev->next = NULL;//cuts contact between second to last and last node
//     last->prev = NULL;//adjusts prev of last node to NULL
//     *stack = last;//shifts head to last node
//     last->next->prev = last;
// }

// void reversed_rotate(t_stack **stack)
// {
//     t_stack *last;
//     //t_stack *second_last;clear

//     if (!*stack || !(*stack)->next)
//         return ;
//     //last = *stack;
//     //second_last = NULL;
//     last = ft_lstlast(*stack);
//     (*stack)->prev = last;          // Adjusts the previous pointer of the first node to point to the last node
//     last->next = *stack;            // Creates circular linked list
//     if (last->prev != NULL)
//         last->prev->next = NULL;
//     else
//     {    // Cuts contact between second to last and last node
//         last->prev = NULL;              // Adjusts prev of the last node to NULL
//         *stack = last;                  // Shifts head to last node
//         last->next->prev = last;        // Corrects the previous pointer of the new first node
//     }
// }

void rev_rotate(t_stack **stack)
{
    t_stack *last;
    t_stack *second_last;

    if (!stack || !*stack || !(*stack)->next)
        return ;
    // Initialize pointers
    last = *stack;
    second_last = NULL;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    // Make the last node the new head
    last->next = *stack;
    last->prev = NULL;
    (*stack)->prev = last;
    // Disconnect the circular link
    if (second_last)
        second_last->next = NULL;
    // Update the head of the list
    *stack = last;
}


void rra(t_stack **stack_a)
{
    printf("rra\n");
    rev_rotate(stack_a);
}

void rrb(t_stack **stack_b)
{
    printf("rrb\n");
    rev_rotate(stack_b);
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
    printf("rrr\n");
    rev_rotate(stack_a);
    rev_rotate(stack_b);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:32:42 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/20 16:00:57 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void    swap(t_stack **stack)
// {
//     t_stack *under;
    
//     under = (*stack)->next;
//     under->next = (*stack);
//     (*stack)->next = under->next;
//     if (under->next != NULL)
//         under->next->prev = (*stack);
//     under->prev = (*stack)->prev;
//     if ((*stack)->prev != NULL)
//         (*stack)->next->prev = under;
//     (*stack)->prev = under;
//     under->next = (*stack);
// }

void    swap(t_stack **stack)
{
    t_stack *under;
    
    under = (*stack)->next;
    
    (*stack)->prev = under;
    (*stack)->next = under->next;

    under->prev = NULL;
    under->next = *stack;
    *stack = under;
}

void    sa(t_stack **stack_a, int *count)
{
    write(1, "sa\n", 3);
    swap(stack_a);
    (*count)++;
}
void    sb(t_stack **stack_b, int *count)
{
    write(1, "sb\n", 3);
    swap(stack_b);
    (*count)++;
}

void    ss(t_stack **stack_a, t_stack **stack_b, int *count)
{
    write (1, "ss\n", 4);
    swap(stack_a);
    swap(stack_b);
    (*count) += 2;
}
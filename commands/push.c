/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:08:43 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/20 15:32:37 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    pushin_p(t_stack **dest, t_stack **src)
{
    t_stack *temp;
    
    if (!*src)
        return ;
    temp = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
    if (!*dest)
    {
        *dest = temp;
        (*dest)->prev = NULL;
        (*dest)->next = NULL;
    }
    else
    {
        temp->next = *dest;
        (*dest)->prev = temp;
        *dest = temp;
    }
}

void    pa(t_stack **stack_a, t_stack **stack_b, int *count)
{
    write (2, "pa\n", 3);
    pushin_p(stack_a, stack_b);
    (*count)++;
}

void    pb(t_stack **stack_a, t_stack **stack_b, int *count)
{
    write (2, "pb\n", 3);
    pushin_p(stack_b, stack_a);
    (*count)++;
}
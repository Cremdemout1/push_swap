/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:35:48 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/27 17:20:01 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *current;

    current = *stack_a;
    while (ft_lstsize(current) > 3)
    {
        pb(stack_a, stack_b);
        current = current->next;
    }
    sort_three(stack_a);
    while (is_it_sorted(stack_a) == UNSORTED)
    {
        assign_data(stack_a, stack_b);
    }
}
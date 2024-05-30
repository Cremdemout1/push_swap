/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:56:02 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/30 13:49:57 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	if (second_last)
		second_last->next = NULL;
	*stack = last;
}

void	rra(t_stack **stack_a)
{
	printf("rra\n");
	rev_rotate(stack_a);
}

void	rrb(t_stack **stack_b)
{
	printf("rrb\n");
	rev_rotate(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	printf("rrr\n");
	rev_rotate(stack_a);
	rev_rotate(stack_b);
}

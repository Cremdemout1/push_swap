/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:39:02 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/30 13:50:12 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*next;

	if (!*stack)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	next = (*stack)->next;
	(*stack)->prev = last;
	last->next = *stack;
	(*stack)->next = NULL;
	next->prev = NULL;
	*stack = next;
}

void	ra(t_stack **stack_a)
{
	printf("ra\n");
	rotate(stack_a);
}

void	rb(t_stack **stack_b)
{
	printf("rb\n");
	rotate(stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	printf("rr\n");
	rotate(stack_a);
	rotate(stack_b);
}

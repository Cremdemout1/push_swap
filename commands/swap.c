/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:32:42 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/30 13:50:38 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*under;

	under = (*stack)->next;
	(*stack)->prev = under;
	(*stack)->next = under->next;
	under->prev = NULL;
	under->next = *stack;
	*stack = under;
}

void	sa(t_stack **stack_a)
{
	printf("sa\n");
	swap(stack_a);
}

void	sb(t_stack **stack_b)
{
	printf("sb\n");
	swap(stack_b);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	printf("ss\n");
	swap(stack_a);
	swap(stack_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:26:41 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/23 16:37:17 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    t_stack *curr;
    t_stack *stati;
    int count;
    
    count = 0;    
    if (argc <= 1)
        return (1);
    stack_a = NULL;
    stack_b = NULL;
    stack_creat(&stack_a, argc, argv);
    curr = stack_a;
	while (curr)
    {
		printf("%d\n", curr->content);
        curr = curr->next;
	}
    sorted_check(&stack_a);
    if(ft_lstsize(stack_a) == 2)  //if list is unsorted and has 2 nodes, swap
    {
        if(stack_a->content > stack_a->next->content)
            sa(&stack_a, &count);
    }
    else if (ft_lstsize(stack_a) == 3)
        sort_three(&stack_a, &count);
    else
        new_sort(&stack_a, &stack_b, &count);
    stati = stack_a;
    while (stati)
    {
        printf("list A: %d\n", stati->content);
        stati = stati->next;
    }
    stati = stack_b;
    while (stati)
    {
        printf("list B: %d\n", stati->content);
        stati = stati->next;
    }
    printf("number of moves: %d\n", count);
    clear_list(&stack_a);
    clear_list(&stack_b);
    return (0);
}
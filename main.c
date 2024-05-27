/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:26:41 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/27 15:34:11 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
  
    if (argc <= 1)
        return (1);
    stack_a = NULL;
    stack_b = NULL;
    stack_creat(&stack_a, argc, argv);
    sorted_check(&stack_a);
    if(ft_lstsize(stack_a) == 2 && stack_a->content > stack_a->next->content)  //if list is unsorted and has 2 nodes, swap
            sa(&stack_a);
    else if (ft_lstsize(stack_a) == 3)
        sort_three(&stack_a);
    else
        new_sort(&stack_a, &stack_b);
    clear_list(&stack_a);
    clear_list(&stack_b);
    return (0);
}
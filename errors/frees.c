/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:59:14 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/17 15:29:51 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    	free_all(t_stack **stack, char **array, char *message, int len)
{
    free_str_array(array);
    clear_list(stack);
    write(1, message, len);
    exit(1);
}

void    del(void *content)
{
    int *ptr;

    ptr = (int *)content;
    free(ptr);
}

void		clear_list(t_stack **lst)
{
    t_stack *temp;
    t_stack *current;
    
    current = *lst;
    while (current)
    {
        temp = current->next;
        del(&current->content);
        current = temp;
    }
    *lst = NULL;
}

void		free_errors(t_stack **lst)
{
    clear_list(lst);
    write(1, "Error\n", 7);
    exit(1);
}
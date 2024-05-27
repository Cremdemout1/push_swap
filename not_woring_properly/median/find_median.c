/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohan <yohan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 09:23:40 by yohan             #+#    #+#             */
/*   Updated: 2024/05/24 09:58:54 by yohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int     find_median(t_stack **stack_a, int size)
{
    int median;
    int *array;

    size = 0;
    array = sort_into_array(stack_a);
    if (size % 2 == 0)//even
        median = (array[size / 2 - 1] + array[size / 2]) / 2;
    else
        median = array[(size + 1) / 2];
    free(array);
    return (median);
}
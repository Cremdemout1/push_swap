/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 07:52:04 by yohan             #+#    #+#             */
/*   Updated: 2024/05/27 12:56:52 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int    get_max(int *array, int size)
{
    int max;
    int i;

    max = 0;
    i = 0;
    while (i < size)
    {
        if (array[i] > max)
            max = array[i];
        i++;
    }
    return (max);
}

void    transfer(int *dest, int *src, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        dest[i] = src[i];
        i++;
    }
}

void    get_digit(int *array, int size, int base)
{
    int i;
    int *storing;
    int *output;
    
    i = 0;
    output = malloc(sizeof(int) * size);
    storing = malloc(sizeof(int) * 10);
    while (i < size)
    {
        storing[(array[i] / base) % 10]++; // counts the amount of occurences of each digit
        i++;
    }
    i = 1;
    while (i < 10)
    {
        storing[i] += storing[i - 1];
        i++;
    }
    i = size - 1;
    while (i >= 0)
    {
        output[i] = storing[(array[i] / base) % 10] - 1;
        storing[(array[i] / base) % 10]--;
        i--;
    }
    transfer(array, output, size);
    free(storing);
    free(output);
}

void    radix_sort(int *array, int size)
{
    int max;
    int base;

    max = get_max(array, size);
    base = 1;
    while (max / base > 0)
    {
        get_digit(array, size, base);
        base *= 10;
    }
}

int    *sort_into_array(t_stack **stack_a)
{
    int i;
    int size;
    int *array;
    t_stack *curr;
    
    curr = *stack_a;
    size = 0;
    while (curr)
    {
        size++;
        curr = curr->next;          
    }
    array = malloc (sizeof(int) * size);
    if (!array)
        return (NULL);
    i = 0;
    curr = *stack_a;
    while (i < size)
    {
        array[i] = curr->content;
        curr = curr->next;
        i++;
    }
    radix_sort(array, size);
    return (array);
}

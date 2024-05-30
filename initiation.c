/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:43:38 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/30 13:09:09 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

char *onearg(int argc, char **argv)
{
    int i;
    char *temp;
    char *spaced;
    
    if (argc <= 1 || argv == NULL)
        return (ft_strdup(""));
    i = 1;
    spaced = ft_strdup("");
    while (i < argc)
    {
        if ( i == 1)
            temp = ft_strdup(argv[1]);
        else
        {
            if (!spaced)
                spaced = ft_strdup("");
            temp = ft_strjoin(spaced, argv[i]);
        }
        free(spaced);
        spaced = ft_strjoin(temp, " ");
        free(temp);
        i++;
    }
    return (spaced);
}

char **all_args(int argc, char **argv)
{
    char *one;
    char **array;    
    
    one = onearg(argc, argv);
    array = ft_split(one, ' ');
    if (array == NULL)
    {
        free(one);
        exit(1);
    }
    free(one);

    if (arg_validity(array) == 1)
    {
        write(1, "Error\n", 7);
        free_str_array(array);
        return (NULL);
    }
    else
        return (array);
}

void	stack_creat(t_stack **stack, int argc, char **argv)
{
    char    **array_arg;
    t_stack  *node_new;
    long    content;
    int     i;

    i = 0;
    array_arg = all_args(argc, argv);
    if (array_arg == NULL)
        exit(1);
    while (array_arg[i])
    {
         content = ft_atol(array_arg[i]);
        if (content > INT_MAX || content < INT_MIN || ft_strlen(array_arg[i]) > 11)
            free_all(stack, array_arg, "Error\n", 7);
        node_new = ft_lstnew(content);
        if (!node_new)
            free_all(stack, array_arg, "Error\n", 7);
        ft_lstadd_back(stack, node_new);
        i++;
    }
    if (duplicate_checker(stack) == 1)
        free_all(stack, array_arg, "Error\n", 7);
    free_str_array(array_arg);
}

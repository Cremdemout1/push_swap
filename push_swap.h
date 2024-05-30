/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:32:53 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/30 13:20:16 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include "./libft/libft.h"

#ifndef UNSORTED
#define UNSORTED 1
#endif

#ifndef SORTED
#define SORTED 0
#endif

typedef struct s_stack
{
    int     		    content;
    int     		    cost;
    int                 index;
    int                 median_value;
    int                 cheapest;
    struct s_stack      *target;
    struct s_stack  	*next;
    struct s_stack  	*prev;
}   				    t_stack;

//commands:
void    	swap(t_stack **stack);
void    	sa(t_stack **stack_a);
void    	sb(t_stack **stack_b);
void    	ss(t_stack **stack_a, t_stack **stack_b);

void    	pushin_p(t_stack **dest, t_stack **src);
void    	pa(t_stack **stack_a, t_stack **stack_b);
void   		pb(t_stack **stack_a, t_stack **stack_b);

void    	rotate(t_stack **stack);
void    	ra(t_stack   **stack_a);
void    	rb(t_stack   **stack_b);
void    	rr(t_stack   **stack_a, t_stack   **stack_b);

void   		rev_rotate(t_stack **stack);
void	    rra(t_stack **stack_a);
void    	rrb(t_stack **stack_b);
void    	rrr(t_stack **stack_a, t_stack **stack_b);
//helper functions:
t_stack     *ft_lstlast(t_stack *lst);
t_stack	    *ft_lstnew(int content);
void	    ft_lstadd_back(t_stack **lst, t_stack *new);
long	    ft_atol(const char *str);
int		    length_of_list(t_stack **stack);
//stack initiation:
void        free_str_array(char **array);
void	    stack_creat(t_stack **stack, int argc, char **argv);
char        *onearg(int argc, char **argv);
//error handling:
void    	free_all(t_stack **stack, char **array, char *message, int len);
void		clear_list(t_stack **lst);
void		free_errors(t_stack **lst);
int    		arg_validity(char **array);
int	    	duplicate_checker(t_stack **stack);
//sorting:
int         is_it_sorted(t_stack **stack);
void        sort_three(t_stack **stack);
void        sorted_check(t_stack **stack_a);
int         node_amount(t_stack **stack);
void        sort(t_stack **stack_a, t_stack **stack_b);
t_stack     *find_smallest(t_stack **stack_a);
int         get_median(t_stack **stack);
void        assign_target(t_stack **stack_a, t_stack **stack_b);
void        assign_index_and_median(t_stack **stack);
void        assign_cheapest(t_stack **stack_b);
void        assign_cost(t_stack **stack_a, t_stack **stack_b);
void        assign_data(t_stack **stack_a, t_stack **stack_b);

void        both_under_median_value(t_stack **stack_a, t_stack **stack_b, t_stack *for_the_top);
void        both_over_median_value(t_stack **stack_a, t_stack **stack_b, t_stack *for_the_top);
void        not_on_same_side(t_stack **stack_a, t_stack **stack_b, t_stack *for_the_top);
void        all_moves(t_stack **stack_a, t_stack **stack_b);

#endif
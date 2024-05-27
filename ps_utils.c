/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:49:12 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/27 17:43:26 by ycantin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*list;

	list = malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
    list->prev = NULL;
	return (list);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*current;

	if (!new || !lst)
		return ;
	current = ft_lstlast(*lst);
	
	if (lst && current)
		current->next = new;
	else
		*lst = new;
}

int	ft_lstsize(t_stack *lst)
{
	int	node_amount;

	node_amount = 0;
	while (lst)
	{
		node_amount++;
		lst = lst->next;
	}
	return (node_amount);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

long	ft_atol(const char *str)
{
	long	i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] <= 57 && str[i] >= 48)
		result = (result * 10) + (str[i++] - 48);
	return (result * sign);
}

int		length_of_list(t_stack **stack)
{
	if (!stack || !*stack)
		return (NULL);
	t_stack *current;
	int i;

	i = 0;
	current = *stack;
	while(current)
	{
		i++;
		current = current->next;
	}
	return (i);
}
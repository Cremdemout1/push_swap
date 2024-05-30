/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:49:12 by ycantin           #+#    #+#             */
/*   Updated: 2024/05/30 13:20:48 by ycantin          ###   ########.fr       */
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

int	length_of_list(t_stack **stack)
{
	t_stack	*current;
	int		i;

	if (!stack || !*stack)
		return (-1);
	i = 0;
	current = *stack;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

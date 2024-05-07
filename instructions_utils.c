/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:03:30 by rboulaga          #+#    #+#             */
/*   Updated: 2024/04/19 19:50:21 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack    *ft_lstnew(int content)
{
    stack    *head;

    head = malloc(sizeof(stack));
    if (!head)
        return (NULL);
    head->data = content;
    head->next = NULL;
    return (head);
}

int	ft_lstsize(stack *list)
{
	int	count;

	count = 0;
	if (!list)
		return (0);
	while (list)
	{
		list = list->next;
		count++;
	}
	return (count);
}

void	ft_lstadd_front(stack **list, stack *new_element)
{
	if (!list || !new_element)
		return ;
	new_element->next = *list;
	*list = new_element;
}

stack	*ft_lstlast(stack *list)
{
	if (!list)
		return (NULL);
	while (list->next)
	{
		list = list->next;
	}
	return (list);
}

void	ft_lstadd_back(stack **lst, stack *nnew)
{
	stack	*head;

	if (!lst || !nnew)
		return ;
	if (!*lst)
		*lst = nnew;
	else
	{
		head = ft_lstlast(*lst);
		head->next = nnew;
	}
}

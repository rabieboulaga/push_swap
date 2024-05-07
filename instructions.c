/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 04:07:15 by rboulaga          #+#    #+#             */
/*   Updated: 2024/05/07 09:52:29 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(stack **list, int order)
{
	if (ft_lstsize(*list) < 2)
		return ;
	stack *beforelast_element;
	stack *last_element;
	beforelast_element = *list;
	last_element = ft_lstlast(*list);
	ft_lstadd_front(list, last_element);
	while (beforelast_element->next != last_element)
		beforelast_element = beforelast_element->next;
	beforelast_element->next = NULL;
	if (order == 1)
		write (1, "rra\n", 4);
	else if (order == 0)
		write (1, "rrb\n", 4);
}

void	rotate(stack **list, int order)
{
	if (ft_lstsize(*list) < 2)
		return ;
	stack *tmp;
	stack *last_element;
	tmp = *list;
	*list = (*list)->next;
	last_element = ft_lstlast(*list);
	last_element->next = tmp;
	tmp->next = NULL;
	if (order == 1)
		write (1, "ra\n", 3);
	else if (order == 0)
		write (1, "rb\n", 3);
}

void	push(stack **source, stack **destination, int order)
{

	// if(!(*source))
	// 	return;
	stack *tmp;
	tmp = *source;
	*source = (*source)->next;
	tmp->next = *destination;
	*destination = tmp;
	if (order == 1)
		write (1, "pa\n", 3);
	else if (order == 0)
		write (1, "pb\n", 3);
}

void	swap(stack **list, int order)
{
	if (ft_lstsize(*list) < 2)
		return ;
	stack *tmp;
	stack *second;
	second = (*list)->next;
	tmp = second->next;
	second->next= *list;
	(*list)->next = tmp;
	*list = second;
	if (order == 1)
		write (1, "sa\n", 3);
	else if (order == 0)
		write (1, "sb\n", 3);
}


// int main()
// {
// 	stack *lawal = ft_lstnew(0);// 0 2 3 4
// 	stack *tani = ft_lstnew(1); // 1 8 9 10
// 	stack *a = ft_lstnew(2);
// 	stack *b = ft_lstnew(3);
// 	stack *c = ft_lstnew(4);
// 	stack *e = ft_lstnew(8);
// 	stack *f = ft_lstnew(9);
// 	stack *g = ft_lstnew(10);



// 	lawal->next = a;
// 	a->next = b;
// 	b->next = c;
// 	c->next = NULL;
// 	tani->next = e;
// 	e->next = f;
// 	f->next = g;
// 	g->next = NULL;

// 	//push(&lawal, &helloworld, 0);
// 	// swap(&lawal, 1);
// 	// rotate(&tani, 0);
// 	// reverse_rotate(&lawal, 0);
// 	rrr(&lawal, &tani);
// 	//  ss(&lawal, &tani);
// 	 //rr(&lawal, &tani);
// 	while (lawal)
// 	{
// 		printf("%lld\n", lawal->data);
// 		lawal = lawal->next;
// 	}

// 	while (tani)
// 	{
// 		printf("%lld\n", tani->data);
// 		tani = tani->next;
// 	}
// 	printf("------------------------------\n");


// }

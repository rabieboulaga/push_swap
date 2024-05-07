/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:10:18 by rboulaga          #+#    #+#             */
/*   Updated: 2024/05/07 09:51:57 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_numbers(stack **stack_a)
{
	int size;
	stack *tmp;

	size = ft_lstsize(*stack_a);
	if (size != 3)
		return;
	tmp = ft_lstlast(*stack_a);
	while ((*stack_a)->data > tmp->data)
		{
			rotate(stack_a, 1);
			tmp = ft_lstlast(*stack_a);
		}
	if ((*stack_a)->next->data < (*stack_a)->data)
		swap(stack_a, 1);
	if ((*stack_a)->next->data > tmp->data)
	{
		reverse_rotate(stack_a, 1);
		swap(stack_a, 1);
	}
}


void	four_numbers(stack **stack_a, stack **stack_b)
{
	int size;
	stack *tmp;
	if (*stack_a == NULL)
		return;

	size  = ft_lstsize(*stack_a);
	if (size != 4)
		return;
	tmp = (*stack_a);
	while (tmp->index != 1)
		tmp = tmp->next;
	define_movements(tmp, stack_a, stack_b, size);
	sort_three_numbers(stack_a);
	push(stack_b, stack_a, 1);
}

void	sort_four_numbers(stack **stack_a, stack **stack_b)
{
	int size;
	stack *tmp;

	if (*stack_a == NULL)
		return;
	size  = ft_lstsize(*stack_a);
	if (size != 4)
		return;
	tmp = (*stack_a);
	while (tmp->index != 0)
		tmp = tmp->next;
	define_movements(tmp, stack_a, stack_b, size);
	sort_three_numbers(stack_a);
	push(stack_b, stack_a, 1);
}



void	five_numbers(stack **stack_a,stack **stack_b)
{
	stack *tmp;
	//stack *tmp2;
	int size;

	size = ft_lstsize(*stack_a);
	if (size != 5)
		return;
	tmp = (*stack_a);
	while (tmp->index != 0)
		tmp = tmp->next;
	define_movements(tmp, stack_a, stack_b, size);
	four_numbers(stack_a, stack_b);
	push(stack_b, stack_a, 1);
}

void define_movements(stack *tmp, stack **stack_a, stack **stack_b, int size)
{
	int i;
	stack *help;

	help = (*stack_a);
	i = 0;
	while(help && help->index != tmp->index)
	{
		i++;
		help =help->next;
	}
	while(i <= (size / 2) && i != 0)
	{
		rotate(stack_a, 1);
		i--;
	}
	while(i > (size / 2) && i < size)
	{
			reverse_rotate(stack_a, 1);
			i++;
	}
	push(stack_a, stack_b, 0);
}

// void sort_three_numbers(stack **stack_a)
// {
// 	int size;

// 	size = ft_lstsize(*stack_a);
// 	if (size != 3)
// 		return;
// 	if((*stack_a)->index == size - 1)
// 	{
// 		rotate(stack_a, 1);
// 		if ((*stack_a)->index != 0)
// 			swap(stack_a, 1);
// 	}
// 	else if ((*stack_a)->index == 1)
// 	{
// 		if ((*stack_a)->next->index != 0)
// 			reverse_rotate(stack_a, 1);
// 		else
// 			swap(stack_a, 1);
// 	}
// 	else
// 	{
// 		reverse_rotate(stack_a, 1);
// 		swap(stack_a, 1);
// 	}
// }

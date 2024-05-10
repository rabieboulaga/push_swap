/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   principal_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:39:43 by rboulaga          #+#    #+#             */
/*   Updated: 2024/05/10 10:26:07 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void basic_push(stack **stack_a, stack **stack_b)
{
	stack *tmp;
	int size;

	size = ft_lstsize(*stack_a);
	if (ft_lstsize(*stack_a) <= 5)
		return;
	while ((*stack_a))
	{
		if ((*stack_a)->index < ft_lstsize(*stack_b))
		{
			push(stack_a, stack_b, 0);
			rotate(stack_b, 0);
		}
		else if ((*stack_a)->index < ft_lstsize(*stack_b) + calculate_disorder(stack_a))
			push(stack_a, stack_b, 0);
		else
			rotate(stack_a, 1);
	}
	while ((*stack_b))
	{
	 	tmp = (*stack_b);
		while(tmp->next && tmp->index != ft_lstsize(*stack_b) - 1)
			tmp = tmp->next;
		best_mouve(tmp, stack_a, stack_b);
	}
}

void best_mouve(stack *tmp, stack **stack_a, stack **stack_b)
{
	int i;
	stack *help;
	int size;

	if(!tmp)
		return;
	size = ft_lstsize(*stack_b);
	help = (*stack_b);
	i = 0;
	while(help && help->index != tmp->index)
	{
		i++;
		help =help->next;
	}
	while(i <= (size / 2) && i != 0)
	{
		rotate(stack_b, 0);
		i--;
	}
	while(i > (size / 2) && i < size)
	{
		reverse_rotate(stack_b, 0);
		i++;
	}
	push(stack_b, stack_a, 1);
}

int	calculate_disorder(stack **stack_a)
{
	int disorder;
	disorder = 0;

	if (ft_lstsize(*stack_a) <= 130)
		disorder = 13;
	else if(ft_lstsize(*stack_a) <= 230 && ft_lstsize(*stack_a) > 130)
		disorder = 21;
	else if (ft_lstsize(*stack_a) > 230)
		disorder = 51;
	return (disorder);
}

// int hello(stack **stack_a)
// {
// 	stack *tmp;
// 	int disorder;

// 	// disorder = 0;
// 	tmp = (*stack_a);
// 	// // while (tmp->next->next->next)
// 	// {
// 		// if (tmp->index > tmp->next->index)
// 			disorder++;
// 		tmp = tmp->next;
// 		if (!tmp)
// 			// break;
// 		// tmp = tmp->next;
// 	// }
// 	printf("%d", disorder);
// 	exit(0);
// 	return(disorder);
// }

// int	calculate_disorder(stack **stack_a)
// {
// 	stack *tmp;
// 	int	disorder;

// 	tmp = (*stack_a);
// 	disorder = 0;
// 	while (tmp->next)
// 	{
// 		if (tmp->data > tmp->next->data)
// 			disorder -= 1;
// 		else if(tmp->data < tmp->next->data)
// 			disorder += 1;
// 		tmp = tmp->next;
// 	}
// 	if (disorder < 0)
// 		disorder = disorder * -1;
// 	if (ft_lstsize(tmp) <= 100 && disorder < 13)
//  	 	disorder = 13;
// 	if ((ft_lstsize(tmp) > 100) && (disorder < 33))
// 		disorder = 33;
// 	return(disorder);
// }
// disorder = it measures the "disorder" or the number of inversions in the stack. If disorder is 0, it means the stack is sorted in non-decreasing order.
// The higher the value of disorder, the more disorder there is in the stack.

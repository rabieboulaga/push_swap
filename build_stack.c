/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 01:04:58 by rboulaga          #+#    #+#             */
/*   Updated: 2024/05/10 11:35:15 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	build_stack(stack **list, long long value)
{
	stack *newnode;

	newnode = (stack *)malloc(sizeof(stack));
	newnode->data = value;
	newnode->next = NULL;
	if (!list)
		ft_lstadd_front(list, newnode);
	ft_lstadd_back(list, newnode);
}
void check_ullong_max(char *str, char **elements, stack **head)
{
	int i;
	int j;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] == '0')
		i++;
	j = i;
	while (str[j])
		j++;
	if ((j - i) >= 11)
		cleaner(elements, head);
}

void free_elements(char **elements)
{
	int i;

	i = 0;
	while (elements && elements[i])
	{
		free(elements[i]);
		i++;
	}
	free(elements);
}
// int mainn()
// {
// 	int value = 10;
// 	stack *stack;

// 	stack = NULL;
// 	build_stack(&stack, value);
// 	while (stack)
// 	{
// 		printf("%d", stack->data);
// 		stack = stack->next;
// 	}
// }

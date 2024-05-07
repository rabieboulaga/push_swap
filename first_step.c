/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:43:09 by rboulaga          #+#    #+#             */
/*   Updated: 2024/04/30 19:48:50 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(stack **head)
{
	int i;
	int	num_elements;
	stack *tmp;
	int size;
	int *array;

	size = ft_lstsize(*head);
	i = 0;
	tmp = (*head);
	num_elements = ft_lstsize(*head);
	array = malloc(sizeof(int) * (num_elements + 1));
	while (tmp)
	{
		array[i] = tmp->data;
		i++;
		tmp = tmp->next;
	}
	array = sorting(array, size);
	set_index(array, head, size);
	free(array);
}

int *sorting(int *array , int size)
{
	int i;
	int x;
	int tmp;

	x = 0;
	i = 0;
	while (i < size - 1)
	{
		x = 0;
		while(x < size-1)
		{
			if (array[x] > array[x + 1])
			{
				tmp = array[x];
				array[x] = array[x + 1];
				array[x + 1] = tmp;
			}
			x++;
		}
			i++;
	}
	return (array);
}

void set_index(int *array, stack **mystack, int size)
{
	int i;
	stack *tmp;

	i = 0;
	tmp  = *mystack;
	while(tmp)
	{
		i = 0;
		while(i < size)
		{
			if (tmp->data == array[i])
			{
				tmp->index = i;
				break;
			}
			i++;
		}
			tmp = tmp->next;
	}
}

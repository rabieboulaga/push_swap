/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:20:54 by rboulaga          #+#    #+#             */
/*   Updated: 2024/05/08 13:27:05 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_sort_stack_a(stack **stack_a)
{
	stack *tmp;

	tmp = (*stack_a);
	while (tmp)
	{
		if (tmp->data < -2147483648 || tmp->data > 2147483647)
			safe_exit(stack_a, 1);
		tmp = tmp->next;
	}
	if (*stack_a == NULL)
		return;
	tmp = (*stack_a);
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			break;
		tmp = tmp->next;
	}
	if (tmp -> next == NULL)
	{
		write (1, "OK\n", 3);
		safe_exit(stack_a, 0);
	}
}



void check_moves(stack **stack_a, stack **stack_b)
{
	char *line;
	int size;

	if (!(*stack_a))
		exit(0);
	size = ft_lstsize(*stack_a);
	check_double(stack_a);
	line = get_next_line(0);
	while (line)
	{
		apply_moves(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	if (size == ft_lstsize(*stack_a))
		check_sort_stack_a(stack_a);
	write (1 , "KO\n", 3);
	just_free(stack_a, stack_b, 0);
}

int main(int	ac, char	**av)
{
	int i;
	char **elements;
	int j;
	long long value;
	stack *stack_a;
	stack *stack_b;

	stack_b = NULL;
	stack_a = NULL;
	i = 1;
	while (i <= ac)
	{
		elements = ft_split(av[i], ' ');
		principal_checker(elements,&stack_a);
		j = 0;
		while (elements && elements[j])
		{
			value = ft_atoi(elements[j]);
			build_stack(&stack_a, value);
			j++;
		}
		free_elements(elements);
		i++;
	}
	check_moves(&stack_a, &stack_b);
}
void just_free(stack **stack_a,stack **stack_b, int order)
{
	stack *tmp;

	while (*stack_a)
	{
		tmp = (*stack_a)->next;
		free (*stack_a);
		(*stack_a) = tmp;
	}
	while (*stack_b)
	{
		tmp = (*stack_b)->next;
		free (*stack_b);
		(*stack_b) = tmp;
	}
	if (order == 1)
	{
		write (1, "Error\n", 6);
		exit(1);
	}
	if (order == 0)
		exit(0);
}

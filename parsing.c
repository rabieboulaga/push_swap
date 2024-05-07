/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:53:58 by rboulaga          #+#    #+#             */
/*   Updated: 2024/05/07 09:52:37 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	cleaner(char **string, stack **head)
{
	int j;

	j = 0;
	while (string[j])
	{
		free (string[j]);
		j++;
	}
	free (string);
	 safe_exit(head, 1);
	// write (2, "error\n", 6);
	// exit (1);
}

void	principal_checker(char **string, stack **head)
{
	int i;
	int j;

	if (!string)
		return ;
	j = 0;
	if (!string[j])
		cleaner(string, head);
	while (string[j])
	{
		i = 0;
		if (!string)
			cleaner(string, head);
		if ((string[j][i] == '-' || string[j][i] == '+') && (string[j][++i] == '\0'))
				cleaner(string, head);
		while (string[j][i])
		{
			if (string[j][i] && (string[j][i] < '0' || string[j][i] > '9'))
				cleaner (string, head);
			i++;
		}
		check_ullong_max(string[j], string, head);
		j++;
	}
}
// int check_empty_string(char **str)
// {
// 	int i;
// 	int j;

// 	while()

// }

void	safe_exit(stack **list, int order)
{
	stack *tmp;

	// if(*list)
	// 	return;
	while (*list)
	{
		tmp = (*list)->next;
		free (*list);
		(*list) = tmp;
	}
	if (order == 1)
	{
		write (2, "Error\n", 6);
		exit(1);
	}
	exit(0);
}

void	check_double(stack **list)
{
	stack *tmp;
	stack *tmp2;

	tmp2 = (*list);
	while(*list)
	{
		tmp = (*list)->next;
		while(tmp)
		{
			if ((*list)->data == tmp->data)
			{
				safe_exit(&tmp2, 1);
				exit(1);
			}
			tmp = tmp->next;
		}
		list = &(*list)->next;
	}
}

void check_sorting(stack **stack_a)
{
	stack *tmp;

	tmp = (*stack_a);
	while (tmp)
	{
		if (tmp->data < -2147483648 || tmp->data > 2147483647)
			safe_exit(stack_a, 1);
		tmp = tmp->next;
	}
	if (ft_lstsize(*stack_a) == 2 && (*stack_a)->data > (*stack_a)->next->data)
		swap(stack_a, 1);
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
			safe_exit(stack_a, 0);
	}
}

// int main(int ac, char **av)
// {
// 	int i;
// 	char **str;

// 	i = 1;
// 	while (i < ac)
// 	{
// 		str = split(av[i], ' ');
// 		principal_checker(str);
// 		i++;
// 	}

// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:56:51 by rboulaga          #+#    #+#             */
/*   Updated: 2024/05/09 19:39:14 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void apply_moves(stack **stack_a, stack **stack_b, char *line)
{
	if (ft_strcmp(line, "sa\n"))
		swap (stack_a, 5);
	else if (ft_strcmp(line, "pa\n"))
		push (stack_b, stack_a, 5);
	else if (ft_strcmp(line, "ra\n"))
		rotate (stack_a, 5);
	else if (ft_strcmp(line, "rra\n"))
		reverse_rotate(stack_a, 5);
	else if (ft_strcmp(line, "rrr\n"))
		rrr(stack_a, stack_b, 5);
	else if (ft_strcmp(line, "ss\n"))
		ss(stack_a, stack_b, 5);
	else if (ft_strcmp(line, "rr\n"))
		rr(stack_a, stack_b, 5);
	else if(ft_strcmp(line, "sb\n"))
		swap (stack_b, 5);
	else if (ft_strcmp(line, "pb\n"))
		push (stack_a, stack_b, 5);
	else if (ft_strcmp(line, "rb\n"))
		rotate (stack_b, 5);
	else if (ft_strcmp(line, "rrb\n"))
		reverse_rotate(stack_b, 5);
	else
		just_free(stack_a, stack_b, 1, line);
}



int	ft_strcmp(char *s1,char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

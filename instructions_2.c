/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 00:19:22 by rboulaga          #+#    #+#             */
/*   Updated: 2024/05/07 15:48:31 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(stack **first_stack, stack **second_stack, int order)
{
	if (ft_lstsize(*first_stack) < 2 && ft_lstsize(*second_stack))
		return ;
	swap(first_stack, 3);
	swap(second_stack, 3);
	if (order == 1)
		write (1, "ss\n", 3);
}

void	rr(stack **first_stack, stack **second_stack, int order)
{
	if (ft_lstsize(*first_stack) < 2 && ft_lstsize(*second_stack))
		return ;
	rotate(first_stack, 3);
	rotate(second_stack, 3);
	if (order == 1)
		write (1, "rr\n", 3);
}
void	rrr(stack **first_stack, stack **second_stack, int order)
{
	if (ft_lstsize(*first_stack) < 2 && ft_lstsize(*second_stack))
		return ;
	reverse_rotate(first_stack, 3);
	reverse_rotate(second_stack, 3);
	if (order == 1)
		write (1, "rrr\n", 4);
}

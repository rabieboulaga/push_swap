/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 03:24:59 by rboulaga          #+#    #+#             */
/*   Updated: 2024/05/07 09:53:50 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print_list(stack **Head)
{
	stack *head = *Head;
	while(head)
	{
		printf("%lld\n", head->data);
		head = head->next;
	}

}


void push_swap(stack **stack_a, stack **stack_b)
{
	check_double(stack_a);
	check_sorting(stack_a);
	sort_array(stack_a);
	sort_three_numbers(stack_a);
	sort_four_numbers(stack_a, stack_b);
	five_numbers(stack_a, stack_b);
	basic_push(stack_a, stack_b);
	safe_exit(stack_a, 5);
}
int main(int ac, char **av)
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
	push_swap(&stack_a, &stack_b);
}

	//return_to_stack_b(&stack_a, &stack_b);
	// (void) array;
	// stack *tmp;
	// tmp = &(*stack_a);

	// while(tmp)
	// {
	// 	printf("[%d , ", tmp->data);
	// 	printf("%d]\n", tmp->index);
	// 	tmp = tmp->next;
	// }
//------------------------------------------------------------------------
// int main(int ac, char **av)
// {
// 	int i;
// 	char **str;
// 	long value;

// 	i = 1;
// 	while (i < ac)
// 	{
// 		str = split(av[i], ' ');
// 		pricipal_cheker(&str);

// 		i++;
// 	}

// }


// int main(int ac, char **av)
// {
// 	int i;
// 	char **str;
// 	int j;

// 	i = 1;
// 	while (i < ac)
// 	{
// 		str = split(av[i], ' ');
// 		j = 0;
// 		while (str[j])
// 		{
// 			printf("%s\n", str[j]);
// 			j++;
// 		}
// 		i++;
// 	}
// 	while (str[j])
// 	{
// 		//exit (0);
// 		j++;
// 	}
// }

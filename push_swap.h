/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboulaga <rboulaga@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 03:37:13 by rboulaga          #+#    #+#             */
/*   Updated: 2024/05/07 15:44:57 by rboulaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct c_stack {
    int index;
	long long data;
    struct c_stack* next;
}	stack;


void ft_print_list(stack **Head);

void	push(stack **source, stack **destination, int order);
void	swap(stack **list, int order);
void	rotate(stack **list, int order);
void	reverse_rotate(stack **list, int order);
void	rrr(stack **first_stack, stack **second_stack, int order);
void	rr(stack **first_stack, stack **second_stack, int order);
void	ss(stack **first_stack, stack **second_stack, int order);
stack	*ft_lstnew(int content);
stack	*ft_lstlast(stack *lst);
int		ft_lstsize(stack *list);
void	ft_lstadd_front(stack **list, stack *new_element);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *string, unsigned int start, size_t len);
//static	unsigned int	numofstr(char const *s, char c);
//static	int	count_char(char *str, char c);
//static	void	free_it(char **ptr, int j);
//static	char	**help_split(char const *s, char c, char **ptr);
char	**ft_split(char const *s, char c);
long long		ft_atoi(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	principal_checker(char **string, stack **head);
void	cleaner(char **string, stack **head);
void	build_stack(stack **list, long long value);
void	ft_lstadd_back(stack **lst, stack *nnew);
// int	ft_lstsize(stack *lst);
void 	ft_print_sun_string(char **av);
void 	push_swap(stack **stack_a, stack **stack_b);
void	check_double(stack **list);
void	safe_exit(stack **list, int order);
void	sort_array(stack **head);
int 	*sorting(int *array , int size);
void 	set_index(int *array, stack **mystack, int size);
void 	sort_three_numbers(stack **stack_a);
void 	check_sorting(stack **stack_a);
void	four_numbers(stack **stack_a, stack **stack_b);
void 	define_movements(stack *tmp, stack **stack_a, stack **stack_b, int size);
void	five_numbers(stack **stack_a,stack **stack_b);
void	sort_four_numbers(stack **stack_a, stack **stack_b);
void	basic_push(stack **stack_a, stack **stack_b);
void	return_to_stack_b(stack **stack_a, stack **stack_b);
void	best_mouve(stack *tmp, stack **stack_a, stack **stack_b);
void 	free_elements(char **elements);
int		calculate_disorder(stack **stack_a);
int 	check_empty_string(char **str);
void	check_ullong_max(char *str, char **elements, stack **head);

int		ft_strcmp(char *s1,char *s2);
void	apply_moves(stack **stack_a, stack **stack_b, char *line);
void	just_free(stack **stack_a,stack **stack_b, int order);
char	*get_next_line(int fd);




#endif

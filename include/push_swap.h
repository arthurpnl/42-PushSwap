/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:29:24 by arpenel           #+#    #+#             */
/*   Updated: 2025/03/15 15:18:46 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_list
{
    int value;
    struct s_list *next;
}   t_list;

// Parse Argument //
t_list *parse_argument(char *test_case);
t_list	*control_args(int	argc, char **argv);
char	**handle_single_argument(char	*test_case);
char	**split_arguments(char *test_case);
char	**split_arguments(char *test_case);

// Argv Check Utils //
int is_valid_number(char *str);
int is_there_space(char *str);
int	validate_and_convert(char *test_case);

// Stack Operations //
void	print_stack(t_list *stack_a);
t_list	*fill_stack(char **numbers);
t_list	*ft_lstnew(int value);
void	add_to_stack(t_list **stack, int value);
int	value_exist_already (t_list **stack_a, int value);


// Stack moves //
void    sa(t_list   **stack_a);
void    sb(t_list **stack_b);
void    ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

// Utils //
char    **ft_split(const char *s, char sep);
int    ft_atoi(const char *nptr);
void    *ft_calloc(size_t nmemb, size_t size);
void    perror_and_exit();



#endif
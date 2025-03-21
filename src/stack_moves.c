/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:24:25 by arpenel           #+#    #+#             */
/*   Updated: 2025/03/17 16:24:28 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_list   **stack_a) // swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
{
    t_list *first;
    t_list *second;

    if (!(*stack_a) || !(*stack_a)->next)
        return ;
    first = *stack_a;
    second = (*stack_a)->next;
    first->next = second->next;
    second->next = first;
    *stack_a = second;
}

void    sb(t_list **stack_b) // swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
{
    t_list  *first;
    t_list  *second;

    if (!(*stack_b) || !(*stack_b)->next)
        return ;
    first = *stack_b;
    second = (*stack_b)->next;
    first->next = second->next;
    second->next = first;
    *stack_b = second;
}

void    ss(t_list **stack_a, t_list **stack_b) // sa and sb at the same time.
{
    sa(stack_a);
    sb(stack_b);
}

void	pa(t_list **stack_a, t_list **stack_b) // push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
{
  	t_list	*temp_node;

	if (!(*stack_b))
		return ;
    temp_node = *stack_b;
    temp_node->next = *stack_a;
	*stack_a = temp_node;
    *stack_b = (*stack_b)->next;
}

void	pb(t_list **stack_a, t_list **stack_b) // push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
{
	t_list	*temp_node;

	if (!(*stack_a))
		return;

	temp_node = *stack_a;
	temp_node->next = *stack_b;
    *stack_b = temp_node;
    *stack_a = (*stack_a)->next;
}

void	ra(t_list **stack_a) // rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
{
	t_list *first_node;
	t_list	*last_node;

	if (!(*stack_a) || !(*stack_a)->next)
          return ;

	last_node = *stack_a;
	while (last_node && last_node->next)
		last_node = last_node->next;

	first_node = *stack_a;
	*stack_a = first_node->next;
	last_node->next = first_node;
	first_node->next = NULL;
}

void	rb(t_list **stack_b) // rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
{
	t_list	*first_node;
	t_list	*last_node;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;

	last_node = *stack_b;
	while (last_node && last_node->next)
		last_node = last_node->next;

	first_node = *stack_b;
	*stack_b = first_node->next;
	last_node->next = first_node;
	first_node->next = NULL;
}

void	rr(t_list **stack_a, t_list **stack_b) // ra and rb at the same time.
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(t_list **stack_a) // reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
{
	t_list	*first_node;
	t_list	*last_node;

	if (!*stack_a || !(*stack_a)->next)
		return;

	last_node = *stack_a;
	while (last_node->next)
		last_node = last_node->next;
	first_node = *stack_a;
	while (first_node->next != last_node)
		first_node = first_node->next;
	last_node->next = *stack_a;
	first_node->next = NULL;
	*stack_a = last_node;
}

void	rrb(t_list **stack_b) // reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
{
	t_list	*first_node;
	t_list	*last_node;

	last_node = *stack_b;
	if (!(*stack_b) || !(*stack_b)->next)
		return;
	while (last_node->next)
		last_node = last_node->next;
	first_node = *stack_b;
	while (first_node->next != last_node)
		first_node = first_node->next;

	last_node->next = *stack_b;
	*stack_b = last_node;
	first_node->next = NULL;
}

void	rrr(t_list **stack_a, t_list **stack_b) // rra and rrb at the same time.
{
	rra(stack_a);
	rrb(stack_b);
}







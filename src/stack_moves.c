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

void    sa(t_list   **stack_a)
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

void    sb(t_list **stack_b)
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

void    ss(t_list **stack_a, t_list **stack_b)
{
    sa(stack_a);
    sb(stack_b);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
  	t_list	*temp_node;

	if (!(*stack_b))
		return ;
    temp_node = *stack_b;
    temp_node->next = *stack_a;
	*stack_a = temp_node;
    *stack_b = (*stack_b)->next;
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_node;

    if (!(*stack_a)
    	return;
	temp_node = *stack_a;
	temp_node->next = *stack_b;
    *stack_b = temp_node;
    *stack_a = (*stack_a)->next;
}

void	ra(t_list **stack_a)
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

void	rb(t_list **stack_b)
{
	t_list	*first_node;
	t_list	*last_node;

	if (!(*stack_b)
		return ;

	last_node = *stack_b;
	while (last_node && last_node->next)
		last_node = last_node->next;

	first_node = *stack_b;
	*stack_b = first_node->next;
	last_node->next = first_node;
	first_node->next = NULL;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}




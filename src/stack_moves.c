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
    sa(*stack_a);
    sb(*stack_b);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
  	t_list	*tmp_stack_b;

	if (!(*stack_b))
		return ;
    tmp_stack_b = *stack_b;
    tmp_stack_b->next = *stack_a;
	*stack_a = tmp_stack_b;
    *stack_b = (*stack_b)->next;
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_stack_a;

    if (!(*stack_a)
    	return;
	tmp_stack_a = *stack_a;
	tmp_stack_a->next = *stack_b;
    *stack_b = tmp_stack_a;
    *stack_a = (*stack_a)->next;
}




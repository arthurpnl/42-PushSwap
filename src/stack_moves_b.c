/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:24:25 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/25 15:22:27 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_list **stack_b)
{
	t_list	*first;
	t_list	*second;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = (*stack_b)->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
}

void	rotate_b(t_list **stack_b)
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

void	reverse_r_b(t_list **stack_b)
{
	t_list	*first_node;
	t_list	*last_node;

	last_node = *stack_b;
	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	while (last_node->next)
		last_node = last_node->next;
	first_node = *stack_b;
	while (first_node->next != last_node)
		first_node = first_node->next;
	last_node->next = *stack_b;
	*stack_b = last_node;
	first_node->next = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:19:29 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/25 15:23:39 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
}

void	rotate_a(t_list **stack_a)
{
	t_list	*first_node;
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

void	reverse_r_a(t_list **stack_a)
{
	t_list	*first_node;
	t_list	*last_node;

	if (!*stack_a || !(*stack_a)->next)
		return ;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targeting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:42:21 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/25 15:24:25 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target_node(t_list *a_node, t_list **stack_b)
{
	t_list	*current;
	t_list	*best_target;
	int		closest_smaller;

	current = *stack_b;
	best_target = NULL;
	closest_smaller = INT_MIN;
	while (current)
	{
		if (current->value < a_node->value && current->value > closest_smaller)
		{
			closest_smaller = current->value;
			best_target = current;
		}
		current = current->next;
	}
	if (!stack_b || !*stack_b)
	{
		a_node->target = NULL;
		return ;
	}
	if (!best_target || a_node->value < find_min_value(*stack_b)
		|| a_node->value > find_max_value(*stack_b))
		find_max_position(a_node, stack_b);
	else
		a_node->target = best_target;
}

void	find_max_position(t_list *a_node, t_list **stack_b)
{
	t_list	*current;
	int		max_value;

	if (!stack_b || !(*stack_b))
	{
		a_node->target = NULL;
		return ;
	}
	current = (*stack_b);
	max_value = find_max_value(*stack_b);
	while (current->value != max_value)
		current = current->next;
	a_node->target = current;
}

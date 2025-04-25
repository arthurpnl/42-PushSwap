/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:45:49 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/25 14:10:22 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_cost(t_list *stack_a, t_list *stack_b)
{
	t_list	*current;
	int		size_a;
	int		size_b;

	size_a = stack_lenght(stack_a);
	size_b = stack_lenght(stack_b);
	current = stack_a;
	while (current)
	{
		if (current->median == 1)
			current->cost = current->index;
		else
			current->cost = size_a - current->index;
		if (current->target)
		{
			if (current->target->median == 1)
				current->cost += current->target->index;
			else
				current->cost += size_b - current->target->index;
		}
		current = current->next;
	}
}

void	find_cheapest_node(t_list *stack)
{
	t_list	*current;
	t_list	*cheapest_node;
	int		min_cost;

	cheapest_node = NULL;
	current = stack;
	min_cost = INT_MAX;
	while (current)
	{
		current->cheapest = false;
		if (current->cost < min_cost)
		{
			min_cost = current->cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = true;
}

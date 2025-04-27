/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:50:27 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/25 16:12:11 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b_max(t_list **stack_b)
{
	t_list	*current;
	int		max_value;

	if (!(*stack_b) || !stack_b)
		return ;
	max_value = find_max_value(*stack_b);
	current = *stack_b;
	while (current && current->value != max_value)
		current = current->next;
	if (!current)
		return ;
	if (current->median == 1)
	{
		while ((*stack_b)->value != max_value)
			rb(stack_b);
	}
	else
		while ((*stack_b)->value != max_value)
			rrb(stack_b);
}

void	rotate_a_target_position(t_list **stack_a, int value_to_insert)
{
	t_list	*current;
	t_list	*target;
	t_list	*min_node;

	current = *stack_a;
	target = NULL;
	min_node = *stack_a;
	while (current)
	{
		if (current->value > value_to_insert)
			if (!target || current->value < target->value)
				target = current;
		if (current->value < min_node->value)
			min_node = current;
		current = current->next;
	}
	if (!target)
		target = min_node;
	while (*stack_a != target)
	{
		if (target->median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

t_list	*find_min_node(t_list *stack, int *min_pos)
{
	t_list	*current;
	t_list	*min;
	int		position;

	current = stack;
	min = stack;
	*min_pos = 0;
	position = 0;
	while (current)
	{
		if (current->value < min->value)
		{
			min = current;
			*min_pos = position;
		}
		current = current->next;
		position++;
	}
	return (min);
}

void	final_sort_stack_a(t_list **stack_a)
{
	t_list	*min;
	int		min_pos;
	int		size;

	min = find_min_node(*stack_a, &min_pos);
	size = stack_lenght(*stack_a);
	if (min_pos <= size / 2)
	{
		while (*stack_a != min)
			ra(stack_a);
	}
	else
	{
		while (*stack_a != min)
			rra(stack_a);
	}
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;

	push_initial_elements(stack_a, stack_b);
	while (stack_lenght(*stack_a) > 3)
	{
		init_index_n_median(*stack_a, *stack_b);
		current = *stack_a;
		while (current)
		{
			find_target_node(current, stack_b);
			current = current->next;
		}
		calculate_cost(*stack_a, *stack_b);
		find_cheapest_node(*stack_a);
		do_cheapest_move(stack_a, stack_b);
	}
	simple_sort_3(stack_a);
	while (*stack_b)
	{
		init_index_n_median(*stack_a, *stack_b);
		rotate_a_target_position(stack_a, (*stack_b)->value);
		pa(stack_a, stack_b);
	}
	final_sort_stack_a(stack_a);
}

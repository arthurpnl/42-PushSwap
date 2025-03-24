/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:50:27 by arpenel           #+#    #+#             */
/*   Updated: 2025/03/19 15:50:32 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_2(t_list **stack_a, t_list **stack_b)
{
	int	lenght;

	lenght = stack_lenght(*stack_a);
	if (lenght >= 5)
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
	}
}

void    simple_sort_3(t_list **stack_a)
{
    int    first;
    int    second;
    int    third;

    first = (*stack_a)->value;
    second = (*stack_a)->next->value;
    third = (*stack_a)->next->next->value;

    if (first > second && second > third && first > third)
    {
        sa(stack_a);
        rra(stack_a);
    }
    else if (first > second && second < third && first > third)
        ra(stack_a);
    else if (first < second && second > third && first > third)
        rra(stack_a);
    else if (first > second && second < third && first > third)
        sa(stack_a);
    else if (first < second && second > third && first < third)
    {
        sa(stack_a);
        ra(stack_a);
    }
}

void    send_first_two(t_list **stack_a, t_list **stack_b)
{
    int    total_elements;

    total_elements = stack_lenght(*stack_a);
    if (total_elements >= 5)
    {
        pb(stack_a, stack_b);
        pb(stack_a, stack_b);
    }
    else if (total_elements == 4)
        pb(stack_a, stack_b);
    else if (total_elements <= 3)
        simple_sort_3(stack_a);
}

void find_target_node(t_list *a_node, t_list **stack_b)
{
    t_list *current;
    t_list *best_target;
    int    closest_smaller;

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
    if (!best_target || a_node->value < find_min_value(*stack_b) || a_node->value > find_max_value(*stack_b))
        find_max_position(a_node, stack_b);
    else
        a_node->target = best_target;
}

void	find_max_position(t_list *a_node, t_list **stack_b)
{
	t_list *current;
	int    max_value;

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

void    calculate_cost(t_list *stack_a, t_list *stack_b)
{
    t_list *current;
    int    size_a;
    int    size_b;

    size_a = stack_lenght(stack_a);
    size_b = stack_lenght(stack_b);
    current = stack_a;
    while(current)
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
	t_list *current;
	t_list *cheapest_node;
	int	min_cost;

	cheapest_node = NULL;
	current = stack;
	min_cost = INT_MAX;
	while (current)
	{
		current->cheapest = false;
		if(current->cost < min_cost)
		{
			min_cost = current->cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = true;
}
///////

void	do_rotation(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	if (cheapest->median == 1 && cheapest->target->median == 1)
	{
		while (*stack_a != cheapest || *stack_b != cheapest->target)
			rr(stack_a, stack_b);
		while (*stack_a != cheapest)
			ra(stack_a);
		while (*stack_b != cheapest)
			rb(stack_b);
	}
	else if (cheapest->median == 2 && cheapest->target->median == 2)
	{
		while (*stack_a != cheapest && *stack_b != cheapest->target)
			rrr(stack_a, stack_b);
		while (*stack_a != cheapest)
			rra(stack_a);
		while (*stack_b != cheapest->target)
			rrb(stack_b);
	}
}

void	do_rotation_opposite(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	if (cheapest->median == 1 && cheapest->target->median == 2)
	{
		while (*stack_a != cheapest)
			ra(stack_a);
		while (*stack_b != cheapest)
			rrb(stack_b);
	}
	else if (cheapest->median == 2 && cheapest->target->median == 1)
	{
		while (*stack_a != cheapest)
			rra(stack_a);
		while (*stack_b != cheapest)
			rb(stack_b);
	}
}

void	do_cheapest_move(t_list **stack_a, t_list **stack_b)
{
	t_list *current;
	t_list *cheapest = NULL;

	current = *stack_a;
while (current)
	{
		if (current->cheapest == true)
		{
			cheapest = current;
			break;
		}
		current = current->next;
	}
	if (!cheapest || !cheapest->target)
		return ;
	if (cheapest->median == 1 && cheapest->target->median == 1)
		do_rotation(stack_a, stack_b, cheapest);
	else if (cheapest->median == 2 && cheapest->target->median == 2)
		do_rotation(stack_a, stack_b, cheapest);
	else
		do_rotation_opposite(stack_a, stack_b, cheapest);
	pb(stack_a, stack_b);

}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	push_2(stack_a, stack_b);
	while(stack_lenght(*stack_a) > 3)
	{
		init_index_n_median(*stack_a, *stack_b);
		t_list *current;

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
}












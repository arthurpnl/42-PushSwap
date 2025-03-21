/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:53:01 by arpenel           #+#    #+#             */
/*   Updated: 2025/03/19 14:53:01 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void    assign_index(t_list **stack)
{
    t_list    *current;
    t_list    *compare;
    int        count;

    current = *stack;
    while (current)
    {
        count = 0;
        compare = *stack;
        while(compare)
        {
            if (current->value > compare->value)
                count++;
            compare = compare->next;
        }
        current->index = count;
        current = current->next;
    }
}
*/

void    set_index(t_list *stack)
{
    int    index;
    t_list *current;

    index = 0;
    current = stack;
    while (current)
    {
        current->index = index;
        current->cost = 0;
        current = current->next;
        index++;
    }
}

void    set_median(t_list *stack)
{
    int    stack_size;
    int    i;

    stack_size = count_stack_lenght(stack);
    i = 0;
    while (stack)
    {
        if(i <= stack_size / 2)
            stack->median = 1;
        else
            stack->median = 2;
        stack = stack->next;
        i++;
    }
}

void    init_index_n_median(t_list *stack_a, t_list *stack_b)
{
    set_index(stack_a);
    set_index(stack_b);
    set_median(stack_a);
    set_median(stack_b);
}

int    find_max_value(t_list *stack)
{
    int    max;
    t_list    *current;

    if (!stack)
        return (-1);

    max = stack->value;
    current = stack->next;
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return (max);
}

int    find_min_value(t_list *stack)
{
    int    min;
    t_list    *current;

    if (!stack)
        return (-1);

    min = stack->value;
    current = stack->next;
    while (current)
    {
        if (current->value < min)
            min = current->value;
        current = current->next;
    }
    return (min);
}

int    stack_lenght(t_list *stack);
{
    int count;
    t_list *current;

    count = 0;
    if (!stack)
        return (0);

    current = stack;
    while (current)
    {
        count++;
        current = current->next;
    }
    return (count);
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
    if (!best_target || a_node->value < find_min_value(stack_b) || a_node->value > find_max_value(stack_b))
        find_max_position(a_node, stack_b);
    else
        a_node->target = best_target;
}

void	find_max_position(t_list *a_node, t_list **stack_b)
{
	t_list *current;
	int    max_value;

	current = (*stack_b);
	max_value = find_max_value(stack_b);
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
        if (current->target->median == 1)
            current->cost += current->target->index;
        else
            current->cost += size_b - current->target->index;
        current = current->next;
    }
}
// trouver la meilleure position
// calculer le cout de push/good positions
// push le nombre le moins couteux au dessus de son target node
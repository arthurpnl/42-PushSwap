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

 */

int    find_max_value(t_list **stack)
{
    int    max;
    t_list    *current;

    if (!stack || !(*stack))
    {
        return (-1);
    }

    max = (*stack)->value;
    current = (*stack)->next;
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return (max);
}

int    find_min_value(t_list **stack)
{
    int    min;
    t_list    *current;

    if (!(*stack))
        return (-1);

    min = (*stack)->value;
    current = (*stack)->next;
    while (current)
    {
        if (current->value < min)
            min = current->value;
        current = current->next;
    }
    return (min);
}

int    count_stack_lenght(t_list **stack)
{
    int    count;
    t_list *current;

    count = 0;
    if (!(*stack || !stack))
        return (0);

    current = *stack;
    while(current)
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



// trouver la meilleure position
// calculer le cout de push/good positions
// push le nombre le moins couteux au dessus de son target node

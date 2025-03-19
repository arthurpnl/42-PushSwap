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

void    assign_index(t_list **stack_a)
{
    t_list    *current;
    t_list    *compare;
    int        count;

    current = *stack_a;
    while (current)
    {
        count = 0;
        compare = *stack_a;
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

int    max_value_b(t_list **stack_b)
{
    int    max;
    t_list    *current;
    if (!(*stack_b))
        return (-1);

    max = stack_b->value;
    current = stack_b->next;
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return (max);
}

int    min_value_b(t_list **stack_b)
{
    int    min;
    t_list    *current;

    if (!(*stack_b))
        return (-1);

    min = (*stack_b)->value;
    current = stack_b->next;
    while (current)
    {
        if (current->value < min)
            min = current->value;
        current = current->next;
    }
    return (min);
}

/*
void    find_target_pos(t_list **stack_b, int value)
{
    t_list *current;

    current =
    if (!(*stack_b)
        return (0);

}
 */
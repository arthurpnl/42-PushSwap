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

void    swap_a(t_list   **stack_a) // swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
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

void    swap_b(t_list **stack_b) // swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
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

void	rotate_a(t_list **stack_a) // rotate a - shift up all elements of stack a by 1. The first element becomes the  last one.
{
    t_list *first_node;
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

void	rotate_b(t_list **stack_b) // rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
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

void	reverse_r_a(t_list **stack_a) // reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
{
    t_list	*first_node;
    t_list	*last_node;

    if (!*stack_a || !(*stack_a)->next)
        return;

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

void	reverse_r_b(t_list **stack_b) // reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
{
    t_list	*first_node;
    t_list	*last_node;

    last_node = *stack_b;
    if (!(*stack_b) || !(*stack_b)->next)
        return;
    while (last_node->next)
        last_node = last_node->next;
    first_node = *stack_b;
    while (first_node->next != last_node)
        first_node = first_node->next;

    last_node->next = *stack_b;
    *stack_b = last_node;
    first_node->next = NULL;
}





























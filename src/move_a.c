/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:24:17 by arpenel           #+#    #+#             */
/*   Updated: 2025/03/27 15:24:18 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_list   **stack_a) // swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
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
    printf("sa\n");
}

void	pa(t_list **stack_a, t_list **stack_b) // push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
{
    t_list	*temp_node;

    if (!(*stack_b))
        return;

    temp_node = *stack_b;           // On stocke le premier élément de stack_b
    *stack_b = (*stack_b)->next;    // On avance stack_b AVANT de toucher à next
    temp_node->next = *stack_a;     // On attache l'ancien top de B au top de A
    *stack_a = temp_node;           // On met temp_node en haut de A
    printf("pa\n");
}

void	ra(t_list **stack_a) // rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
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
    printf("ra\n");
}

void	rra(t_list **stack_a) // reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
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
    printf("rra\n");
}
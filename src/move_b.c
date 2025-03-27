/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:28:41 by arpenel           #+#    #+#             */
/*   Updated: 2025/03/27 15:28:41 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void    sb(t_list **stack_b) // swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
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
    printf("sb\n");
}

void	pb(t_list **stack_a, t_list **stack_b) // push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
{
    t_list	*temp;

    if (!*stack_a)
        return;
    temp = *stack_a;
    *stack_a = (*stack_a)->next;  // avance d'abord stack_a
    temp->next = *stack_b;        // puis rattache à stack_b
    *stack_b = temp;
    printf("pb\n");
}

void	rb(t_list **stack_b) // rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
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
    printf("rb\n");
}

void	rrb(t_list **stack_b) // reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
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
    printf("rrb\n");
}
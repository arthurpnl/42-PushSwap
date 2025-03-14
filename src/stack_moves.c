/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:35:28 by arpenel           #+#    #+#             */
/*   Updated: 2025/03/14 16:16:16 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_list   **stack_a)
{
    t_list *first;
    t_list *second;
    
    if(!(stack_a) || !(*stack_a)->next)
        return ;
    first = *stack_a;
    second - first->next;

    first->next = second->next;
}
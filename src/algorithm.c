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

void    send_first_two(t_list **stack_a, t_list **stack_b)
{
    int    total_elements;

    total_elements = count_stack_a(stack_a);
    if (total_elements >= 5)
    {
        pb(stack_a, stack_b);
        pb(stack_a, stack_b);
    }
    else if (total_elements = 4)
        pb(stack_a, stack_b);
    else if (total_elements <= 3)
        simple_sort(stack_a);
}


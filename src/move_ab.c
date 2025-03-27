/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:27:07 by arpenel           #+#    #+#             */
/*   Updated: 2025/03/27 15:27:08 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void    ss(t_list **stack_a, t_list **stack_b) // sa and sb at the same time.
{
    swap_a(stack_a);
    swap_b(stack_b);
    printf("ss\n");
}

void	rr(t_list **stack_a, t_list **stack_b) // ra and rb at the same time.
{
    rotate_a(stack_a);
    rotate_b(stack_b);
    printf("rr\n");
}

void	rrr(t_list **stack_a, t_list **stack_b) // rra and rrb at the same time.
{
    reverse_r_a(stack_a);
    reverse_r_b(stack_b);
    printf("rrr\n");
}
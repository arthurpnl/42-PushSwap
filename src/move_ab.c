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


#include "pushswap.h"

void    ss(t_list **stack_a, t_list **stack_b) // sa and sb at the same time.
{
    sa(stack_a);
    sb(stack_b);
    printf("ss\n");
}

void	rr(t_list **stack_a, t_list **stack_b) // ra and rb at the same time.
{
    ra(stack_a);
    rb(stack_b);
    printf("rr\n");
}

void	rrr(t_list **stack_a, t_list **stack_b) // rra and rrb at the same time.
{
    rra(stack_a);
    rrb(stack_b);
    printf("rrr\n");
}
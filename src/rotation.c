/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:48:05 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/25 15:13:40 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotation(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	if (cheapest->median == 1 && cheapest->target->median == 1)
	{
		while (*stack_a != cheapest && *stack_b != cheapest->target)
			rr(stack_a, stack_b);
		while (*stack_a != cheapest)
			ra(stack_a);
		while (*stack_b != cheapest->target)
			rb(stack_b);
	}
	else if (cheapest->median == 2 && cheapest->target->median == 2)
	{
		while (*stack_a != cheapest && *stack_b != cheapest->target)
			rrr(stack_a, stack_b);
		while (*stack_a != cheapest)
			rra(stack_a);
		while (*stack_b != cheapest->target)
			rrb(stack_b);
	}
}

void	do_rotation_opposite(t_list **stack_a, t_list **stack_b,
		t_list *cheapest)
{
	if (cheapest->median == 1 && cheapest->target->median == 2)
	{
		while (*stack_a != cheapest)
			ra(stack_a);
		while (*stack_b != cheapest->target)
			rrb(stack_b);
	}
	else if (cheapest->median == 2 && cheapest->target->median == 1)
	{
		while (*stack_a != cheapest)
			rra(stack_a);
		while (*stack_b != cheapest->target)
			rb(stack_b);
	}
}

void	do_cheapest_move(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	t_list	*cheapest;

	cheapest = NULL;
	current = *stack_a;
	while (current)
	{
		if (current->cheapest == true)
		{
			cheapest = current;
			break ;
		}
		current = current->next;
	}
	if (!cheapest || !cheapest->target)
		return ;
	if (cheapest->median == 1 && cheapest->target->median == 1)
		do_rotation(stack_a, stack_b, cheapest);
	else if (cheapest->median == 2 && cheapest->target->median == 2)
		do_rotation(stack_a, stack_b, cheapest);
	else
		do_rotation_opposite(stack_a, stack_b, cheapest);
	pb(stack_a, stack_b);
}

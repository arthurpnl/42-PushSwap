/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:38:05 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/25 15:16:07 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_initial_elements(t_list **stack_a, t_list **stack_b)
{
	int	lenght;

	lenght = stack_lenght(*stack_a);
	if (lenght > 3)
	{
		if (lenght > 5)
		{
			pb(stack_a, stack_b);
			pb(stack_a, stack_b);
		}
		else
			pb(stack_a, stack_b);
	}
}

void	send_first_two(t_list **stack_a, t_list **stack_b)
{
	int	total_elements;

	total_elements = stack_lenght(*stack_a);
	if (total_elements >= 5)
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
	}
	else if (total_elements == 4)
		pb(stack_a, stack_b);
	else if (total_elements <= 3)
		simple_sort_3(stack_a);
}

void	init_index_n_median(t_list *stack_a, t_list *stack_b)
{
	set_index(stack_a);
	set_index(stack_b);
	set_median(stack_a);
	set_median(stack_b);
}

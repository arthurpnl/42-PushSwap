/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:35:11 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/29 14:01:13 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		stack_len;

	stack_b = NULL;
	stack_a = control_args(argc, argv);
	if (!stack_a)
		return (1);
	stack_len = stack_lenght(stack_a);
	if (stack_len == 1)
		return (free_stack(stack_a), 0);
	else if (stack_len == 2)
		simple_sort_2(&stack_a);
	else if (stack_len == 3)
		simple_sort_3(&stack_a);
	else
		sort_stack(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

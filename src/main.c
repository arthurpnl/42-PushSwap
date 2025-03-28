/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:35:11 by arpenel           #+#    #+#             */
/*   Updated: 2025/03/15 15:24:01 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


void	print_stacks(t_list *stack_a, t_list *stack_b)
{
    printf("\n--- STACK A ---\n");
    while (stack_a)
    {
        printf("val: %d | idx: %d | cost: %d | med: %d | cheapest: %d\n",
            stack_a->value, stack_a->index, stack_a->cost,
            stack_a->median, stack_a->cheapest);
        stack_a = stack_a->next;
    }

    printf("\n--- STACK B ---\n");
    while (stack_b)
    {
        printf("val: %d | idx: %d | cost: %d | med: %d | cheapest: %d\n",
            stack_b->value, stack_b->index, stack_b->cost,
            stack_b->median, stack_b->cheapest);
        stack_b = stack_b->next;
    }
}


int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b = NULL;
    int stack_len;

    stack_a = control_args(argc, argv);
    if (!stack_a)
        return (1);

    stack_len = stack_lenght(stack_a);
	if (stack_len == 1)
		return (0);
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




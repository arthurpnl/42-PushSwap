/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:53:01 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/25 15:16:20 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_lenght(t_list *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	set_index(t_list *stack)
{
	int		index;
	t_list	*current;

	index = 0;
	current = stack;
	while (current)
	{
		current->index = index;
		current->cost = 0;
		current = current->next;
		index++;
	}
}

void	set_median(t_list *stack)
{
	int	stack_size;
	int	i;

	stack_size = stack_lenght(stack);
	i = 0;
	while (stack)
	{
		if (i <= stack_size / 2)
			stack->median = 1;
		else
			stack->median = 2;
		stack = stack->next;
		i++;
	}
}

int	find_max_value(t_list *stack)
{
	int		max;
	t_list	*current;

	if (!stack)
		return (-1);
	max = stack->value;
	current = stack->next;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	find_min_value(t_list *stack)
{
	int		min;
	t_list	*current;

	if (!stack)
		return (-1);
	min = stack->value;
	current = stack->next;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

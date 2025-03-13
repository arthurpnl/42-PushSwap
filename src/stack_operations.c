/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:29:00 by arpenel           #+#    #+#             */
/*   Updated: 2025/03/13 14:56:02 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *stack_a) // will be removed in the future
{
	while (stack_a)
	{
		printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
}

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	add_to_stack(t_list **stack, int value)
{
	t_list	*tmp;
	
	tmp = ft_lstnew(value);
	if (!tmp)
	{
		write(2, "Error/n", 6);
		exit(1);
	}
	tmp->next = *stack;
	*stack = tmp;
}

t_list	*fill_stack(char **numbers)
{
	t_list *stack_a;
	int	i;
	int	value;

	stack_a = NULL;
	i = 0;
	value = 0;
	while (numbers[i])
	{
		value = validate_and_convert(numbers[i]);
		add_to_stack(&stack_a, value);
		i++;
	}
	return (stack_a);
}
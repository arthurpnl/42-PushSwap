/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:29:00 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/29 11:56:29 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_list	*tmp2;

	tmp = ft_lstnew(value);
	if (!*stack)
	{
		*stack = tmp;
		return ;
	}
	tmp2 = *stack;
	if (!tmp)
		perror_and_exit();
	while (tmp2->next)
	{
		tmp2 = tmp2->next;
	}
	tmp2->next = tmp;
}

int	value_exist_already(t_list **stack_a, int value)
{
	t_list	*current;

	current = *stack_a;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

t_list	*fill_stack(char **numbers)
{
	t_list	*stack_a;
	t_list	*new_node;
	t_list	*current;
	int		i;
	int		value;

	stack_a = NULL;
	current = NULL;
	i = 0;
	while (numbers[i])
	{
		value = validate_and_convert(stack_a, numbers, numbers[i]);
		if (value_exist_already(&stack_a, value))
			(free_split(numbers), free_stack(stack_a), perror_and_exit());
		new_node = ft_lstnew(value);
		if (!stack_a)
			stack_a = new_node;
		else
			current->next = new_node;
		current = new_node;
		i++;
	}
	return (stack_a);
}

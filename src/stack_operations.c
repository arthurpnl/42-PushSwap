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
		perror_and_exit();
	tmp->next = *stack;
	*stack = tmp;
}

int	value_exist_already (t_list **stack_a, int value)
{
	t_list *current;

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
    t_list *stack_a = NULL;
    t_list *new_node;
    t_list *current = NULL;
    int	i = 0;
    int	value;

    while (numbers[i])
    {
        value = validate_and_convert(numbers[i]);
        if (value_exist_already(&stack_a, value))
            perror_and_exit();
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

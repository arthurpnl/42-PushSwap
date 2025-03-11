/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:29:58 by arpenel           #+#    #+#             */
/*   Updated: 2025/03/11 15:30:12 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*parse_argument(char *test_case) // replace test_case by argv[1]
{
	t_list	*stack_a;
	t_list	*tmp;
	char	**numbers;
	int		i;
	int		value;

	i = 0;
	stack_a = NULL;
	tmp = NULL;
	if (is_there_space(test_case) == 1)
		numbers = ft_split(test_case, ' ');
	if (!numbers)
		return (NULL);
	while (numbers[i])
	{
		if (!is_valid_number(numbers[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		value = ft_atoi(numbers[i]);
		tmp = ft_lstnew(value);
		tmp->next = stack_a;
		stack_a = tmp;
		i++;
	}
	return (stack_a);
}
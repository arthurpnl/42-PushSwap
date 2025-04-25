/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:29:58 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/25 15:12:41 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*control_args(int argc, char **argv)
{
	t_list	*stack_a;
	int		i;
	int		value;

	stack_a = NULL;
	i = 1;
	value = 0;
	if (argc < 2)
		return (NULL);
	if (argc == 2 && is_there_space(argv[1]))
		return (parse_argument(argv[1]));
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			perror_and_exit();
		value = ft_atoi(argv[i]);
		if (!value_exist_already(&stack_a, value))
			add_to_stack(&stack_a, value);
		else
			perror_and_exit();
		i++;
	}
	return (stack_a);
}

t_list	*parse_argument(char *test_case)
{
	char	**numbers;
	t_list	*stack;

	if (!test_case || test_case[0] == '\0')
		return (NULL);
	numbers = split_arguments(test_case);
	if (!numbers)
		return (NULL);
	stack = fill_stack(numbers);
	free_split(numbers);
	return (stack);
}

char	**handle_single_argument(char *test_case)
{
	char	**numbers;

	numbers = malloc(sizeof(char *) * 2);
	if (!numbers)
		return (NULL);
	numbers[0] = test_case;
	numbers[1] = '\0';
	return (numbers);
}

char	**split_arguments(char *test_case)
{
	if (is_there_space(test_case) == 1)
		return (ft_split(test_case, ' '));
	else
		return (handle_single_argument(test_case));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:29:58 by arpenel           #+#    #+#             */
/*   Updated: 2025/03/13 10:32:05 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*parse_argument(char *test_case) // replace test_case by argv[1]
{
	char	**numbers;

	if(!test_case || test_case[0] == '\0')
		return (NULL);
	numbers = split_arguments(test_case);
	if (!numbers)
		return (NULL);
	return (fill_stack(numbers));
}

char	**handle_single_argument(char	*test_case)
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



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:45:44 by arpenel           #+#    #+#             */
/*   Updated: 2025/03/13 14:56:30 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i] || (str[i] < '0' || str[i] > '9'))
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_there_space(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	validate_and_convert(char *test_case)
{
	if (!is_valid_number(test_case))
		perror_and_exit();
	return (ft_atoi(test_case));
}

/*
int	main(void)
{
	char	*test_case = "3294 3459s2 4";
	t_list	*stack_a = parse_argument(test_case);
	if(test_case[0] == '\0')
		return (1);
	print_stack(stack_a);
	return (0);
}
*/

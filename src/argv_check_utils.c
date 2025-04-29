/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:45:44 by arpenel           #+#    #+#             */
/*   Updated: 2025/04/29 14:11:45 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (n > ft_strlen(s2))
		return (1);
	else if (n < ft_strlen(s2))
		return (0);
	else 
	{
		if (s1[i] == '-' && s2[i] != '-')
			s1++;
		while ((s1[i] || s2[i]))
		{
			if (s1[i] != s2[i])
				return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
			i++;
		}
	}
	return (0);
}

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
	if (ft_strncmp(str, "2147483647", ft_strlen(str)) > 0 || ft_strncmp(str, "-2147483648", ft_strlen(str)) > 0)
		return (0);
	return (1);
}

// int	is_there_space(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (!str[i])
// 		return (0);
// 	while (str[i])
// 	{
// 		if (str[i] == ' ')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

int	validate_and_convert(t_list	*stack_a, char **numbers, char *test_case)
{
	if (!is_valid_number(test_case))
		(free_split(numbers), free_stack(stack_a), perror_and_exit());
	return (ft_atoi(test_case));
}

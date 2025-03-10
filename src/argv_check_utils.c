/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:45:44 by arpenel           #+#    #+#             */
/*   Updated: 2025/03/10 15:10:12 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>


int is_valid_number(char *str)
{
    int i;
    
    i = 0;
    if(!str[i])
        return (0);
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (!str[i] || (str[i] < '0' && str[i] > '9'))
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int is_there_space(char *str)
{
    int i;
    
    i = 0;
    if (!str[i])
        return (0);
    while (str[i])
    {
        if(str[i] == ' ')
            return (1);
        i++;
    }
    return (0);
}

t_node *parse_argument(char *test_case)
{
    char    **numbers;
    int i;
    int value;

    i = 0;
    if (is_there_space(test_case) == 1)
        numbers = ft_split(test_case, ' ');
    while(numbers[i])
    {
        if (!is_valid_number(numbers[i]))
        {
            write(2, "Error\n", 6);
            exit(1);
        }
        value = ft_atoi(numbers[i]);
        i++;

        // need to stack the values into chained list
        // how ??? 
    }
    return (*numbers);
}

/*
int main(void)
{
    char *test_case = "43 9234 23 5205 252";
    parse_argument(test_case);
    return (0);
}
*/





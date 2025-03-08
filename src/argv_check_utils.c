/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:45:44 by arpenel           #+#    #+#             */
/*   Updated: 2025/03/08 12:36:11 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_valid_number(char *str)
{
    int i;
    int is_it_valid;

    i = 0;
    is_it_valid = 0;
    if(str[0] == '\0')
        return (0);
    while (str[i])
    {
        if (str[0] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
            is_it_valid = 1;
        else
            return (0);
        if (str[0] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
            is_it_valid = 1;
        else
            return (0);
        if (str[i] >= '0' && str[i] <= '9')
            is_it_valid = 1;
    }
    return (is_it_valid);
}

char **parse_argument(int   argc, char **argv)
{
    ft_split(str, ' ');
}

char    *parse_single_argument(char *str)
{
    
}

int is_there_space(char *str)
{
    int i;
    int is_there_space;
    
    i = 0;
    is_a_string = 0;
    while (str[i])
    {
        if(str[i] == ' ')
        {
            is_a_string = 1;
            return (is_there_space);
        }
        else
            i++;
    }
    return (is_there_space);
}
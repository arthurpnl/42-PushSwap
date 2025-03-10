/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:45:44 by arpenel           #+#    #+#             */
/*   Updated: 2025/03/10 14:06:06 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

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

t_node *parse_argument(int  argc, char **argv)
{
    if (is_there_space(argv[1]) == 1 )
    ft_split(str, ' ');
}
    
/*
int main(void)
{
    int i;

    i = 0;
    char *test_case[] = {
        "42", "43 234 535  345", "32234", "", NULL
    };
    while (test_case[i])
    {
        printf("Test \"%s\" → %d\n", test_case[i], is_there_space(test_case[i]));
        i++;
    }
    return (0);
}
*/

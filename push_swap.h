/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:29:24 by arpenel           #+#    #+#             */
/*   Updated: 2025/03/10 15:45:17 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

typedef struct s_list
{
    int value;
    struct s_list *next;
}   t_list;

t_node *parse_argument(char *test_case);
int is_valid_number(char *str);
int is_there_space(char *str);
char	**ft_split(const char *s, char sep);
int	ft_atoi(const char *nptr);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:35:11 by arpenel           #+#    #+#             */
/*   Updated: 2025/03/07 15:37:22 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (argc == 2)
		parse_argument(argc, **argv);
	
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:35:11 by arpenel           #+#    #+#             */
/*   Updated: 2025/03/15 15:24:01 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a; 
	//t_list	*stack_b;//

	stack_a = control_args(argc, argv);
	//stack_b = NULL;//
	print_stack(stack_a);
	return (0);
}
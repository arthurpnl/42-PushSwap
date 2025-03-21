/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:53:01 by arpenel           #+#    #+#             */
/*   Updated: 2025/03/19 14:53:01 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    assign_index(t_list **stack)
{
    t_list    *current;
    t_list    *compare;
    int        count;

    current = *stack;
    while (current)
    {
        count = 0;
        compare = *stack;
        while(compare)
        {
            if (current->value > compare->value)
                count++;
            compare = compare->next;
        }
        current->index = count;
        current = current->next;
    }
}

int    max_value(t_list **stack)
{
    int    max;
    t_list    *current;
    if (!(*stack))
        return (-1);

    max = (*stack)->value;
    current = (*stack)->next;
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return (max);
}

int    min_value(t_list **stack)
{
    int    min;
    t_list    *current;

    if (!(*stack))
        return (-1);

    min = (*stack)->value;
    current = (*stack)->next;
    while (current)
    {
        if (current->value < min)
            min = current->value;
        current = current->next;
    }
    return (min);
}

int    count_stack_lenght(t_list **stack)
{
    int    count;
    t_list *current;

    count = 0;
    if (!(*stack || !stack))
        return (0);

    current = *stack;
    while(current)
    {
        count++;
        current = current->next;
    }
    return (count);
}


int find_target_node(t_list **stack_b, int value_to_push) {
    t_list *current;
    t_list *target_node = NULL;
    int index = 0;
    int target_index = 0;
    int max_value;

    if (!(*stack_b))
        return (0); // Si STACK_B est vide, on place directement en haut

    max_value = max_value(stack_b); // Récupère la valeur max de STACK_B
    current = *stack_b;

    // Parcourir STACK_B pour trouver la closest smaller value
    while (current)
    {
        if (current->value < value_to_push) // Si la valeur actuelle est plus petite que value_to_push
        {
            // Vérifier si c'est la plus grande valeur plus petite que value_to_push
            if (!target_node || current->value > target_node->value)
            {
                target_node = current;
                target_index = index;
            }
        }
        current = current->next;
        index++;
    }

    // Si aucun plus petit nombre trouvé, on prend le max_value comme target
    if (!target_node)
    {
        current = *stack_b;
        index = 0;
        while (current->value != max_value) // On cherche où se trouve le max
        {
            current = current->next;
            index++;
        }
        return index; // Placer après le maximum (au-dessus, pas en dessous)
    }

    return target_index; // Retourne l'index où insérer value_to_push pour respecter l'ordre décroissant
}


// trouver la meilleure position
// calculer le cout de push/good positions
// push le nombre le moins couteux

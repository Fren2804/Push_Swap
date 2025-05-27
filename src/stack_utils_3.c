/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-21 12:29:54 by franmore          #+#    #+#             */
/*   Updated: 2025-03-21 12:29:54 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief This function checks that there are no duplicate values 
/// among the nodes.
/// @param stack The stack with the nodes.
/// @return Returns 1 in case of an error, and 0 in case of success.
int	ft_stack_numbers_equals(t_stack **stack)
{
	t_node	*node;
	t_node	*aux;
	int		value;

	if (!stack || !(*stack))
		return (0);
	node = (*stack)->head;
	while (node->next)
	{
		value = node->value;
		aux = node->next;
		while (aux)
		{
			if (value == aux->value)
			{
				write(2, "Error\n", 6);
				return (1);
			}
			aux = aux->next;
		}
		node = node->next;
	}
	return (0);
}

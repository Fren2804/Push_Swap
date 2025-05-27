/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-06 17:54:14 by franmore          #+#    #+#             */
/*   Updated: 2025-03-06 17:54:14 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

void	ft_free_stack(t_stack **stack)
{
	t_node	*node;
	t_node	*node_aux;

	if (!stack || !(*stack))
		return ;
	node = (*stack)->head;
	while (node)
	{
		node_aux = node;
		node = node->next;
		node_aux->before = NULL;
		node_aux->next = NULL;
		free(node_aux);
	}
	(*stack)->head = NULL;
	(*stack)->tail = NULL;
	free((*stack));
	(*stack) = NULL;
}

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

void	ft_assign_index_stack(t_stack **stack)
{
	int		i;
	int		index;
	int		number;
	t_node	*node_temp;

	i = 0;
	index = 0;
	while (i < (*stack)->size)
	{
		node_temp = (*stack)->head;
		while (node_temp && node_temp->index != -1)
			node_temp = node_temp->next;
		number = node_temp->value;
		while (node_temp)
		{
			if ((number > node_temp->value) && (node_temp->index == -1))
				number = node_temp->value;
			node_temp = node_temp->next;
		}
		ft_assign_index_node(stack, number, index);
		index ++;
		i ++;
	}
}

void	ft_assign_index_node(t_stack **stack, int number, int index)
{
	t_node	*node_temp;

	node_temp = (*stack)->head;
	while (node_temp)
	{
		if (node_temp->value == number)
		{
			node_temp->index = index;
			break ;
		}
		node_temp = node_temp->next;
	}
}

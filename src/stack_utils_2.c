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

#include "../inc/push_swap.h"

/// @brief This function assigns an index to each node of the stack.
/// @param stack The with all the nodes.
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

/// @brief This function assigns an index to the node with the given number.
/// @param stack The stack containing all the nodes.
/// @param number The number of the target node.
/// @param index The index value to assign to the node.
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

/// @brief This function gets the highest index.
/// @param stack The stack with the nodes.
/// @return The value of the index.
int	ft_index_min(t_stack **stack)
{
	int		index;
	int		num;
	t_node	*node_temp;

	if (!(*stack) || !(*stack)->head)
		return (-1);
	node_temp = (*stack)->head;
	num = node_temp->value;
	index = node_temp->index;
	while (node_temp)
	{
		if (num > node_temp->value)
		{
			num = node_temp->value;
			index = node_temp->index;
		}
		node_temp = node_temp->next;
	}
	return (index);
}

/// @brief This function gets the lowest index.
/// @param stack The stack with the nodes.
/// @return The value of the index.
int	ft_index_max(t_stack **stack)
{
	int		index;
	int		num;
	t_node	*node_temp;

	if (!(*stack) || !(*stack)->head)
		return (-1);
	node_temp = (*stack)->head;
	num = node_temp->value;
	index = node_temp->index;
	while (node_temp)
	{
		if (num < node_temp->value)
		{
			num = node_temp->value;
			index = node_temp->index;
		}
		node_temp = node_temp->next;
	}
	return (index);
}

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

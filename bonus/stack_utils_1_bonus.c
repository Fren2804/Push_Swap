/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-06 17:15:04 by franmore          #+#    #+#             */
/*   Updated: 2025-03-06 17:15:04 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

t_stack	*ft_stack_new(void)
{
	t_stack	*stack;

	stack = NULL;
	stack = (t_stack *) malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*ft_node_new(int number)
{
	t_node	*node;

	node = NULL;
	node = (t_node *) malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = number;
	node->next = NULL;
	node->before = NULL;
	node->index = -1;
	return (node);
}

void	ft_add_node(t_stack **stack, int value)
{
	t_node	*new_node;

	new_node = ft_node_new(value);
	if (!new_node)
		return ;
	if (!(*stack)->head)
	{
		(*stack)->head = new_node;
		(*stack)->tail = new_node;
	}
	else
		ft_stack_node(stack, new_node);
	(*stack)->size++;
}

void	ft_stack_node(t_stack **stack, t_node *new_node)
{
	t_node	*temp_node;

	temp_node = (*stack)->head;
	while (temp_node->next)
		temp_node = temp_node->next;
	temp_node->next = new_node;
	new_node->before = temp_node;
	(*stack)->tail = new_node;
}

int	ft_sorted_stack(t_stack **stack, int menor_mayor)
{
	t_node	*node_temp;

	if (!(*stack)->head)
		return (1);
	node_temp = (*stack)->head;
	if (menor_mayor)
	{
		while (node_temp->next)
		{
			if (node_temp->index > node_temp->next->index)
				return (0);
			node_temp = node_temp->next;
		}
	}
	else
	{
		while (node_temp->next)
		{
			if (node_temp->index < node_temp->next->index)
				return (0);
			node_temp = node_temp->next;
		}
	}
	return (1);
}

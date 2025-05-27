/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-13 20:45:24 by franmore          #+#    #+#             */
/*   Updated: 2025-03-13 20:45:24 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief This is the first part of the algorithm: it moves all nodes to 
/// stack B in a specific order.
/// @param stack_a The stack to sort.
/// @param stack_b The auxiliary stack.
void	ft_divide_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	range;

	if ((*stack_a)->size > 7)
		range = ft_sqrt((*stack_a)->size) * 13 / 10;
	else
		range = (*stack_a)->size / 2;
	i = 0;
	while ((*stack_a)->head)
	{
		if ((*stack_a)->head->index <= i)
		{
			ft_pab(stack_b, stack_a, 2);
			ft_rab(stack_b, 2);
			i++;
		}
		else if ((*stack_a)->head->index <= i + range)
		{
			ft_pab(stack_b, stack_a, 2);
			i++;
		}
		else
			ft_rab(stack_a, 1);
	}
}

/// @brief This function moves each node from stack B into the correct position.
/// It searches for the correct node from both the head and the tail.
/// Highest number to lowest.
/// @param stack_a The stack to sort.
/// @param stack_b The auxiliary stack.
void	ft_sort_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int		index;
	t_node	*node_head;
	t_node	*node_tail;

	while ((*stack_b)->head && (*stack_b)->tail)
	{
		index = (*stack_b)->size - 1;
		node_head = (*stack_b)->head;
		node_tail = (*stack_b)->tail;
		while (node_head && node_tail && index >= 0)
		{
			if (node_head->index == index)
				index = ft_movements_head(stack_a, stack_b, index);
			else if (node_tail->index == index)
				index = ft_movements_tail(stack_a, stack_b, index);
			else
			{
				node_head = node_head->next;
				node_tail = node_tail->before;
			}
		}
	}
}

/// @brief This function searches for the correct node using the head and sends 
/// it to stack A. If it encounters the next node along the way, 
/// it sends that one too.
/// @param stack_a The stack to sort.
/// @param stack_b The auxiliary stack.
/// @param index The index of the node to push.
/// @return It returns -1 to indicate to the previous while loop to search 
/// for the next node/index.
int	ft_movements_head(t_stack **stack_a, t_stack **stack_b, int index)
{
	int	second;

	second = 0;
	while ((*stack_b)->head->index != index)
	{
		if ((*stack_b)->head->index == index - 1)
		{
			ft_pab(stack_a, stack_b, 1);
			ft_rab(stack_a, 1);
			second = 1;
		}
		else
			ft_rab(stack_b, 2);
	}
	ft_pab(stack_a, stack_b, 1);
	if (second)
		ft_rrab(stack_a, 1);
	return (-1);
}

/// @brief This function searches for the correct node using the tail and sends 
/// it to stack A. If it encounters the next node along the way, 
/// it sends that one too.
/// @param stack_a The stack to sort.
/// @param stack_b The auxiliary stack.
/// @param index The index of the node to push.
/// @return It returns -1 to indicate to the previous while loop to search 
/// for the next node/index.
int	ft_movements_tail(t_stack **stack_a, t_stack **stack_b, int index)
{
	int	second;

	second = 0;
	while ((*stack_b)->tail->index != index)
	{
		if ((*stack_b)->tail->index == index - 1)
		{
			ft_rrab(stack_b, 2);
			ft_pab(stack_a, stack_b, 1);
			ft_rab(stack_a, 1);
			second = 1;
		}
		else
			ft_rrab(stack_b, 2);
	}
	ft_rrab(stack_b, 2);
	ft_pab(stack_a, stack_b, 1);
	if (second)
		ft_rrab(stack_a, 1);
	return (-1);
}

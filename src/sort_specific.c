/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_specific.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-10 12:03:04 by franmore          #+#    #+#             */
/*   Updated: 2025-03-10 12:03:04 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief This function is to sort a stack of with two nodes.
/// @param stack The stack to sort.
/// @param a_b This parameter is used to identify the stack.
void	ft_sort_stack_2(t_stack **stack, int a_b)
{
	t_node	*node_temp;

	node_temp = (*stack)->head;
	if (node_temp->index > node_temp->next->index)
		ft_sab(stack, a_b);
}

/// @brief This function is to sort a stack of with three nodes.
/// @param stack The stack to sort.
void	ft_sort_stack_3(t_stack **stack)
{
	int		position_max;
	int		max_index;
	t_node	*node_temp;

	node_temp = (*stack)->head;
	max_index = ft_index_max(stack);
	position_max = 0;
	while (node_temp)
	{
		if (node_temp->index == max_index)
			break ;
		node_temp = node_temp->next;
		position_max ++;
	}
	if (position_max == 0)
		ft_rab(stack, 1);
	else if (position_max == 1)
		ft_rrab(stack, 1);
	node_temp = (*stack)->head;
	if (node_temp->index > node_temp->next->index)
		ft_sab(stack, 1);
}

/// @brief This function is to sort a stack of with four nodes.
/// @param stack_a The stack to sort.
/// @param stack_b The auxiliary stack.
void	ft_sort_stack_4(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*node_temp;
	int		index_min;

	ft_pab(stack_b, stack_a, 2);
	ft_sort_stack_3(stack_a);
	ft_pab(stack_a, stack_b, 1);
	if (ft_sorted_stack(stack_a, 1))
		return ;
	node_temp = (*stack_a)->head;
	index_min = ft_index_min(stack_a);
	if (node_temp->index == index_min + 3)
		ft_rab(stack_a, 1);
	else if (node_temp->index == index_min + 1)
		ft_sab(stack_a, 1);
	else if (node_temp->index == index_min + 2)
	{
		ft_rrab(stack_a, 1);
		ft_sab(stack_a, 1);
		ft_rab(stack_a, 1);
		ft_rab(stack_a, 1);
	}
}

/// @brief This is a supporting function for sort_stack_5.
/// @param stack_a The stack to sort.
/// @param stack_b The auxiliary stack.
static void	ft_sort_stack_5_aux(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->head->index == 4 || (*stack_a)->head->index == 3)
		ft_pab(stack_b, stack_a, 2);
	else
	{
		ft_sab(stack_a, 1);
		ft_pab(stack_b, stack_a, 2);
	}
	if ((*stack_a)->tail->index == 4 || (*stack_a)->tail->index == 3)
	{
		ft_rrab(stack_a, 1);
		ft_pab(stack_b, stack_a, 2);
	}
	else
		ft_pab(stack_b, stack_a, 2);
	ft_sort_stack_2(stack_b, 2);
	ft_sort_stack_3(stack_a);
	ft_pab(stack_a, stack_b, 1);
	ft_rab(stack_a, 1);
	ft_pab(stack_a, stack_b, 1);
	ft_rab(stack_a, 1);
}

/// @brief This function is to sort a stack of with five nodes.
/// @param stack_a The stack to sort.
/// @param stack_b The auxiliary stack.
void	ft_sort_stack_5(t_stack **stack_a, t_stack **stack_b)
{

	if ((*stack_a)->head->next->next->index == 1
		&& (*stack_a)->head->next->next->next->index == 0)
	{
		return (ft_sort_stack_5_aux(stack_a, stack_b));
	}
	if ((*stack_a)->head->index == 0 || (*stack_a)->head->index == 1)
		ft_pab(stack_b, stack_a, 2);
	if ((((*stack_a)->tail->index == 0) || ((*stack_a)->tail->index == 1)))
	{
		ft_rrab(stack_a, 1);
		ft_pab(stack_b, stack_a, 2);
	}
	while ((*stack_a)->size > 3)
	{
		ft_rab(stack_a, 1);
		if ((*stack_a)->head->index == 0 || (*stack_a)->head->index == 1)
			ft_pab(stack_b, stack_a, 2);
	}
	if ((*stack_b)->head->index == 0)
		ft_rab(stack_b, 2);
	ft_sort_stack_3(stack_a);
	ft_pab(stack_a, stack_b, 1);
	ft_pab(stack_a, stack_b, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-28 10:39:54 by franmore          #+#    #+#             */
/*   Updated: 2025-02-28 10:39:54 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief This function swap first and second node.
/// @param stack The stack to operate on.
/// @param s This parameter, ranging from 0 to 2, is used to indicate 
///	whether it's ss, sa or sb.
void	ft_sab(t_stack **stack, int s)
{
	t_node	*node_aux1;
	t_node	*node_aux2;

	if (!(*stack) || !(*stack)->head || !(*stack)->tail || (*stack)->size < 2)
		return ;
	node_aux1 = (*stack)->head;
	node_aux2 = node_aux1->next;
	if ((*stack)->size > 2)
		node_aux2->next->before = node_aux1;
	node_aux1->next = node_aux2->next;
	node_aux1->before = node_aux2;
	node_aux2->before = NULL;
	node_aux2->next = node_aux1;
	(*stack)->head = node_aux2;
	if ((*stack)->size == 2)
		(*stack)->tail = node_aux1;
	if (s == 1)
		write(1, "sa\n", 3);
	else if (s == 2)
		write(1, "sb\n", 3);
}

/// @brief This fuction call sa and sb.
/// @param stack_a The stack a to operate on.
/// @param stack_b The stack b to operate on.
void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_sab(stack_a, 0);
	ft_sab(stack_b, 0);
	write(1, "ss\n", 3);
}

/// @brief This function push the first node of one stack to the other.
/// @param stack_gain The stack that receives a node. 
/// @param stack_loss The stack that losses a node. 
/// @param p This parameter, ranging from 1 to 2, is used to indicate 
///	whether it's pa or pb
void	ft_pab(t_stack **stack_gain, t_stack **stack_loss, int p)
{
	t_node	*node_temp;

	if (!(*stack_loss) || !(*stack_loss)->head || !(*stack_gain))
		return ;
	node_temp = (*stack_loss)->head;
	(*stack_loss)->head = (*stack_loss)->head->next;
	if ((*stack_loss)->head)
		(*stack_loss)->head->before = NULL;
	node_temp->next = (*stack_gain)->head;
	(*stack_gain)->head = node_temp;
	if (node_temp->next)
		node_temp->next->before = node_temp;
	else
		(*stack_gain)->tail = node_temp;
	(*stack_gain)->size++;
	(*stack_loss)->size--;
	if ((*stack_loss)->size == 0)
	{
		(*stack_loss)->head = NULL;
		(*stack_loss)->tail = NULL;
	}
	if (p == 1)
		write(1, "pa\n", 3);
	else if (p == 2)
		write(1, "pb\n", 3);
}

/// @brief This function rotates all the nodes upwards.
/// @param stack The stack to operate on.
/// @param r This parameter, ranging from 0 to 2, is used to indicate 
///	whether it's rr, ra or rb.
void	ft_rab(t_stack **stack, int r)
{
	t_node	*node_last;
	t_node	*node_first;

	if (!(*stack) || !(*stack)->head || !(*stack)->head->next)
		return ;
	node_last = (*stack)->tail;
	node_first = (*stack)->head;
	(*stack)->head = node_first->next;
	(*stack)->head->before = NULL;
	node_first->before = node_last;
	node_first->next = NULL;
	node_last->next = node_first;
	(*stack)->tail = node_first;
	if (r == 1)
		write(1, "ra\n", 3);
	else if (r == 2)
		write(1, "rb\n", 3);
}

/// @brief This function rotates all the nodes downwards.
/// @param stack The stack to operate on.
/// @param r This parameter, ranging from 0 to 2, is used to indicate 
///	whether it's rrr, rra or rrb.
void	ft_rrab(t_stack **stack, int r)
{
	t_node	*node_last;
	t_node	*node_first;

	if (!(*stack) || !(*stack)->head || !(*stack)->head->next)
		return ;
	node_last = (*stack)->tail;
	node_first = (*stack)->head;
	node_last->next = node_first;
	(*stack)->tail = node_last->before;
	node_last->before->next = NULL;
	node_last->before = NULL;
	node_first->before = node_last;
	(*stack)->head = node_last;
	if (r == 1)
		write(1, "rra\n", 4);
	else if (r == 2)
		write(1, "rrb\n", 4);
}

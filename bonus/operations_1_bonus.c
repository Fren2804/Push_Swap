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

#include "../inc/checker_bonus.h"

void	ft_sab(t_stack **stack, int s)
{
	t_node	*node_aux1;
	t_node	*node_aux2;

	(void) s;
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
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_sab(stack_a, 0);
	ft_sab(stack_b, 0);
}

//stack_gain stack_loss
void	ft_pab(t_stack **stack_gain, t_stack **stack_loss, int p)
{
	t_node	*node_temp;

	(void) p;
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
}

void	ft_rab(t_stack **stack, int r)
{
	t_node	*node_last;
	t_node	*node_first;

	(void) r;
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
}

void	ft_rrab(t_stack **stack, int r)
{
	t_node	*node_last;
	t_node	*node_first;

	(void) r;
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
}

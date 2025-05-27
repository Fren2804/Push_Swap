/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-08 14:51:51 by franmore          #+#    #+#             */
/*   Updated: 2025-03-08 14:51:51 by franmore         ###   ########.es       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief This function calls the sorting algorithm when the number of 
///	nodes is greater than 5.
/// @param stack_a The stack to sort.
/// @param stack_b The auxiliary stack.
void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	ft_divide_stack_a(stack_a, stack_b);
	ft_sort_to_a(stack_a, stack_b);
}

/// @brief This function is the main sorting function.
/// @param stack_a The stack to sort.
/// @param stack_b The auxiliary stack.
void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_sorted_stack(stack_a, 1))
		return ;
	else if ((*stack_a)->size <= 1)
		return ;
	else if ((*stack_a)->size == 2)
		ft_sort_stack_2(stack_a, 1);
	else if ((*stack_a)->size == 3)
		ft_sort_stack_3(stack_a);
	else if ((*stack_a)->size == 4)
		ft_sort_stack_4(stack_a, stack_b);
	else if ((*stack_a)->size == 5)
		ft_sort_stack_5(stack_a, stack_b);
	else
		ft_sort_stack(stack_a, stack_b);
}

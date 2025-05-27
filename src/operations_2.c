/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-28 11:44:55 by franmore          #+#    #+#             */
/*   Updated: 2025-02-28 11:44:55 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief This fuction call ra and rb
/// @param stack_a The stack a to operate on.
/// @param stack_b The stack b to operate on.
void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rab(stack_a, 0);
	ft_rab(stack_b, 0);
	write(1, "rr\n", 3);
}

/// @brief This fuction call rra and rrb
/// @param stack_a The stack a to operate on.
/// @param stack_b The stack a to operate on.
void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rrab(stack_a, 0);
	ft_rrab(stack_b, 0);
	write(1, "rrr\n", 4);
}

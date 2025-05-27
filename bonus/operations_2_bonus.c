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

#include "../inc/checker_bonus.h"

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rab(stack_a, 0);
	ft_rab(stack_b, 0);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rrab(stack_a, 0);
	ft_rrab(stack_b, 0);
}

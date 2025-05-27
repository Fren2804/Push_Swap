/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-22 13:34:09 by franmore          #+#    #+#             */
/*   Updated: 2025-03-22 13:34:09 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"
#include "../inc/get_next_line.h"

static int	ft_control_input(t_stack **stack_a, t_stack **stack_b,
	char *instruction)
{
	if (!ft_strcmp(instruction, "pa"))
		ft_pab(stack_a, stack_b, 1);
	else if (!ft_strcmp(instruction, "pb"))
		ft_pab(stack_b, stack_a, 2);
	else if (!ft_strcmp(instruction, "ra"))
		ft_rab(stack_a, 1);
	else if (!ft_strcmp(instruction, "rb"))
		ft_rab(stack_a, 1);
	else if (!ft_strcmp(instruction, "rr"))
		ft_rr(stack_a, stack_b);
	else if (!ft_strcmp(instruction, "rra"))
		ft_rrab(stack_a, 1);
	else if (!ft_strcmp(instruction, "rrb"))
		ft_rrab(stack_a, 1);
	else if (!ft_strcmp(instruction, "rrr"))
		ft_rrr(stack_a, stack_b);
	else if (!ft_strcmp(instruction, "sa"))
		ft_sab(stack_a, 1);
	else if (!ft_strcmp(instruction, "sb"))
		ft_sab(stack_a, 1);
	else
		return (1);
	return (0);
}

int	ft_main_function(t_stack **stack_a, t_stack **stack_b)
{
	char	*instruction;

	instruction = get_next_line(0);
	while (instruction != NULL)
	{
		instruction[ft_strlen(instruction) - 1] = '\0';
		if (ft_control_input(stack_a, stack_b, instruction))
		{
			write(1, "Error\n", 6);
			ft_free_stack(stack_a);
			ft_free_stack(stack_b);
			free(instruction);
			return (1);
		}
		free(instruction);
		instruction = get_next_line(0);
	}
	if (ft_sorted_stack(stack_a, 1) && !(*stack_b)->head)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}

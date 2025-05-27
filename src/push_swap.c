/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-06 17:14:28 by franmore          #+#    #+#             */
/*   Updated: 2025-03-06 17:14:28 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief This function frees the memory of the array of numbers. 
/// @param numbers The array of numbers to free.
static void	ft_free_matrix(char **numbers)
{
	int	i;

	if (!numbers)
		return ;
	i = 0;
	while (numbers[i] != NULL)
	{
		free(numbers[i]);
		i ++;
	}
	free(numbers);
}

/// @brief This function is responsible for checking the content
/// of the argument in case there are only two (Program Input), 
///	and if everything is good, put the numbers into the stack a. 
/// @param argv The argv that we need.
/// @param stack_a The stack used to store the numbers.
/// @return Returns 1 in case of an error, and 0 in case of success.
static int	ft_argv_2(char *argv, t_stack **stack_a)
{
	char	**numbers;
	int		i;

	i = 0;
	numbers = ft_split(argv, ' ');
	if (numbers[0] == NULL)
	{
		write(2, "Error\n", 6);
		ft_free_matrix(numbers);
		return (1);
	}
	if (ft_control_argv(numbers, 1))
	{
		ft_free_matrix(numbers);
		return (1);
	}
	i = 0;
	while (numbers[i] != NULL)
	{
		ft_add_node(stack_a, ft_atoi(numbers[i]));
		i ++;
	}
	ft_free_matrix(numbers);
	return (0);
}

/// @brief This function is responsible for checking the content
/// of the arguments in case there are more than two, 
///	and if everything is good, put the numbers into the stack a. 
/// @param argv The arguments that we need to check.
/// @param stack_a The stack used to store the numbers.
/// @return Returns 1 in case of an error, and 0 in case of success.
static int	ft_argc_more_2(char *argv[], t_stack **stack_a)
{
	int	i;

	if (ft_control_argv(argv, 0))
		return (1);
	i = 1;
	while (argv[i] != NULL)
	{
		ft_add_node(stack_a, ft_atoi(argv[i]));
		i ++;
	}
	return (0);
}

/// @brief This function initializes the stacks.
/// @param stack_a The stack a to initialize.
/// @param stack_b The stack b to initialize.
static void	ft_init_aux(t_stack **stack_a, t_stack **stack_b)
{
	(*stack_a) = NULL;
	(*stack_b) = NULL;
	(*stack_a) = ft_stack_new();
	(*stack_b) = ft_stack_new();
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	ft_init_aux(&stack_a, &stack_b);
	if (ft_control_argc(argc, argv))
		return (ft_free_stack(&stack_a), ft_free_stack(&stack_b), 1);
	if (argc == 1)
		return (ft_free_stack(&stack_a), ft_free_stack(&stack_b), 0);
	if (argc == 2)
	{
		if (ft_argv_2(argv[1], &stack_a))
			return (ft_free_stack(&stack_a), ft_free_stack(&stack_b), 1);
	}
	else
	{
		if (ft_argc_more_2(argv, &stack_a))
			return (ft_free_stack(&stack_a), ft_free_stack(&stack_b), 1);
	}
	if (ft_stack_numbers_equals(&stack_a))
		return (ft_free_stack(&stack_a), ft_free_stack(&stack_b), 1);
	ft_assign_index_stack(&stack_a);
	ft_sort(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}

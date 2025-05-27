/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-26 14:00:44 by franmore          #+#    #+#             */
/*   Updated: 2025-02-26 14:00:44 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

int	analyze_numbers(char *number)
{
	int	i;
	int	control;

	control = 0;
	i = 0;
	while (number[i] != '\0' && control == 0)
	{
		if (i == 0)
		{
			if (!ft_isdigit(number[0]) && number[0] != '+' && number[0] != '-')
				control = 1;
		}
		else
		{
			if (!ft_isdigit(number[i]))
				control = 1;
		}
		i ++;
	}
	return (control);
}

int	lenght_number(char *str)
{
	long	number;
	int		sign;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str == '0')
		str++;
	if (ft_strlen(str) > 12)
		return (1);
	number = sign * ft_atol(str);
	if (number > INT_MAX || number < INT_MIN)
		return (1);
	return (0);
}

int	repeat_number(char *argv[], int control)
{
	int		i;
	int		j;

	i = 1;
	if (control)
		i = 0;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (!ft_strcmp(argv[i], argv[j]))
				return (1);
			j ++;
		}
		i ++;
	}
	return (0);
}

int	ft_control_argv(char *argv[], int control)
{
	int	i;
	int	error;

	error = 0;
	i = 1;
	if (control)
		i = 0;
	while (argv[i] != NULL && !error)
	{
		if (analyze_numbers(argv[i]))
			error = 3;
		if (lenght_number(argv[i]) && !error)
			error = 4;
		i ++;
	}
	if (repeat_number(argv, control) && !error)
		error = 5;
	if (error)
		write(2, "Error\n", 6);
	return (error);
}

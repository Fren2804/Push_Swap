/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_argc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-21 10:21:27 by franmore          #+#    #+#             */
/*   Updated: 2025-03-21 10:21:27 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

int	ft_argv_analyze_2(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if ((argv[i] == '+' || argv[i] == '-') && (!ft_isdigit(argv[i + 1])))
			return (1);
		if (argv[i] != '+' && argv[i] != '-' && !ft_isdigit(argv[i])
			&& argv[i] != ' ')
			return (1);
		i ++;
	}
	return (0);
}

int	ft_control_argc(int argc, char *argv[])
{
	int	error;

	error = 0;
	if (argc == 2)
	{
		if (ft_argv_analyze_2(argv[1]))
			error = 1;
	}
	if (error)
		write(2, "Error\n", 6);
	return (error);
}

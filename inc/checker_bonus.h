/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-22 12:50:21 by franmore          #+#    #+#             */
/*   Updated: 2025-03-22 12:50:21 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*before;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

t_stack	*ft_stack_new(void);
t_node	*ft_node_new(int number);
void	ft_stack_node(t_stack **stack, t_node *new_node);
void	ft_add_node(t_stack **stack, int value);
void	ft_free_stack(t_stack **stack);
void	ft_assign_index_stack(t_stack **stack);
void	ft_assign_index_node(t_stack **stack, int numbder, int index);
void	ft_divide_stack_a(t_stack **stack_a, t_stack **stack_b);
int		ft_index_min(t_stack **stack);
int		ft_index_max(t_stack **stack);
int		ft_sorted_stack(t_stack **stack, int menor_mayor);
void	ft_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_stack_2(t_stack **stack);
void	ft_sort_stack_3(t_stack **stack);
void	ft_sort_stack_4(t_stack **stack_a, t_stack **stack_b);
void	ft_divide_stack_a(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_to_a(t_stack **stack_a, t_stack **stack_b);
int		ft_movements_head(t_stack **stack_a, t_stack **stack_b, int index);
int		ft_movements_tail(t_stack **stack_a, t_stack **stack_b, int index);
int		ft_control_argc(int argc, char *argv[]);
int		ft_control_argv(char *argv[], int control);
int		ft_stack_numbers_equals(t_stack **stack);

//bonus

int		ft_main_function(t_stack **stack_a, t_stack **stack_b);

//operations

void	ft_sab(t_stack **stack, int s);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_pab(t_stack **stack_gain, t_stack **stack_loss, int p);
void	ft_rab(t_stack **stack, int r);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rrab(t_stack **stack, int r);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);

//libft

long	ft_atol_push(const char *str);
long	ft_atol(const char *str);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
int		ft_isspace(char c);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_sqrt(int nb);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	**ft_split(char const *str, char c);

#endif
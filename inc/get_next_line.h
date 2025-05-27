/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-24 21:31:49 by franmore          #+#    #+#             */
/*   Updated: 2025-01-24 21:31:49 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t num, size_t size);
char	*ft_substr_gnl(char const *str, unsigned int start, size_t len);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_free(char *final, char *temp);

#endif
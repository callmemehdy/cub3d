/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-akar <mel-akar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 06:09:23 by ael-amma          #+#    #+#             */
/*   Updated: 2024/10/05 11:09:43 by mel-akar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

// char	*ft_updaterest(char *rest);
// char	*ft_getline(char *rest);
// char	*ft_getrest(int fd, char *rest);
char	*get_next_line(int fd);

size_t	ft_strlen(char *str);
// void	ft_bzero(char *str);
char	*ft_strchr(char *s, int c);
void	*ft_memcpy(void *dst, void *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);

#endif
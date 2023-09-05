/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbozan <sbozan@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 07:14:48 by anargul           #+#    #+#             */
/*   Updated: 2023/09/05 21:53:20 by sbozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

void	*ft_memcpy(void	*dst, const void *src, size_t n);
char	*ft_strdup(char	*str1);
char	*get_next_line(int fd);
char	*ft_strchr(char *str, int c);
int 	ft_strlen(char *str);
char	*ft_strjoin(char *str, char *buff);
char	*get_buff(int fd, char *str);
char	*get_returnline(char *str);
char	*dlt_line(char *str);
#endif

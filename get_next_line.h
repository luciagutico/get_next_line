/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/12 16:27:22 by anagutie      #+#    #+#                 */
/*   Updated: 2023/11/28 11:41:54 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(char const *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*read_and_append_file(int fd, char *static_buffer);
char	*prepare_next_line(char *buffer);
char	*copying_line(char *static_buffer);
char	*ft_free(char **buffer);

#endif
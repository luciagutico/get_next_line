/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anagutie <anagutie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/12 16:26:33 by anagutie      #+#    #+#                 */
/*   Updated: 2023/11/27 16:59:22 by anagutie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	bytes;
	void	*allocation;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if ((nmemb * size) / size != nmemb)
		return (NULL);
	bytes = nmemb * size;
	allocation = malloc(bytes);
	if (allocation == NULL)
		return (NULL);
	ft_bzero (allocation, bytes);
	return (allocation);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char*s1, char*s2)
{
	int		new_len;
	char	*new_string;
	int		i;
	int		j;

	i = 0;
	new_len = ft_strlen(s1) + ft_strlen(s2);
	new_string = ft_calloc(sizeof(char), new_len + 1);
	if (new_string == NULL)
		return (ft_free(&s1));
	while (s1[i] != '\0')
	{
		new_string[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new_string[i] = s2[j];
		i++;
		j++;
	}
	ft_free(&s1);
	return (new_string);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == '\0' && (char) c == '\0')
		return ((char *)s + i);
	return (NULL);
}

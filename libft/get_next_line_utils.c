/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:36:07 by lbouchon          #+#    #+#             */
/*   Updated: 2022/12/20 17:20:13 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i] != (char)c)
		if (s[i] == 0)
			return (NULL);
	return ((char *)&s[i]);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
		return (ft_strdup_gnl(s2));
	str = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2)) + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s1 && s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2 && s2[j])
	{
		str[i] = s2[j++];
		i++;
	}
	str[i] = '\0';
	free((char *)s1);
	return (str);
}

char	*ft_strdup_gnl(const char *s)
{
	char	*str;
	int		i;

	if (!s[0])
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen_gnl(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (ft_strlen_gnl(s) < len)
		len = ft_strlen_gnl(s);
	if (!s)
		return (NULL);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (start > (unsigned int)ft_strlen_gnl(s))
	{
		str[0] = '\0';
		return (str);
	}
	i = 0;
	while (s[start] && (i < len))
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

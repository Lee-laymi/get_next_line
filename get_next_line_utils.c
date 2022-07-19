/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:05:53 by skrairab          #+#    #+#             */
/*   Updated: 2022/07/19 22:53:55 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s, int mode)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (mode == 1)
	{
		while (s[i])
			i++;
	}
	if (mode == 2)
	{
		while (s[i] != '\0' && s[i] != '\n')
			i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*str;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	str = ((char *)malloc(ft_strlen(s1, 1) + ft_strlen(s2, 1) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}

char	*ft_strlcpy(char *dst, char *src)
{
	size_t	i;

	i = 0;
	if (src == NULL)
	{
		return (NULL);
	}
	dst = (char *)malloc(ft_strlen(src, 2) + 2);
	if (dst == NULL)
		return (NULL);
	while (src[i] && src[i] != '\n')
	{
		dst[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dst[i++] = '\n';
	dst[i] = '\0';
	return (dst);
}

char	*ft_a(char *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\0' || s[i + 1] == '\0' || s == NULL)
	{
		free(s);
		return (NULL);
	}
	str = (char *)malloc(ft_strlen(s, 1) - i + 1);
	if (str == NULL)
		return (NULL);
	while (s[i + j + 1])
	{
		str[j] = s[i + j + 1];
		j++;
	}
	str[j] = '\0';
	free(s);
	return (str);
}

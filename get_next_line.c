/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:36:46 by skrairab          #+#    #+#             */
/*   Updated: 2022/06/17 02:20:27 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = ((char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
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
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	size_t	i;

	i = 0;
	if (destsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < (destsize - 1) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	if (i < destsize)
	{
		while (src[i] != '\0')
			i++;
		return (i);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static	t_stash	p[OPEN_MAX];
	int	readed;
	int	i;
	char	*nline;

	nline = NULL;
	if (fd < 0 || (BUFFER_SIZE < 0))
		return (NULL);
	p[fd].buffer = (char *)malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!p[fd].buffer || read(fd, p[fd].buffer, 0) < 0)
		return (NULL);
	if (p[fd].p == NULL)
	{
		p[fd].p = malloc(sizeof(char));
		p[fd].p[0] = '\0';
		p[fd].start = 0;
	}
	i = p[fd].start;
	while (p[fd].buffer != NULL)
	{
		readed = read(fd, p[fd].buffer, BUFFER_SIZE);
		p[fd].p = ft_strjoin(p[fd].p, p[fd].buffer);
		while (p[fd].p[i] != '\n' && p[fd].p[i] != '\0')
			i++;
		if (p[fd].p[i] == '\n')
		{
			nline = (char *)malloc(sizeof(char) * (i + 1));
			ft_strlcpy(nline, p[fd].p + p[fd].start, (i + 2));
			p[fd].start = (i + 1);
		//	printf("%s\n", p[fd].p);
		//	printf("%d\n", p[fd].start);
		//	free(nline);
			return (nline);
		}
		return (NULL);
	}
	return (NULL);
}

/*int	main()
{
	int	fd;
	char	*line;

	fd = open("test", O_RDONLY);
		line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		line = get_next_line(fd);
		free(line);
	}
}*/

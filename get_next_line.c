/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:36:46 by skrairab          #+#    #+#             */
/*   Updated: 2022/07/05 00:08:28 by skrairab         ###   ########.fr       */
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
	while (i < ft_strlen(s1, 1))
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2, 1))
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
	dst = (char *)malloc(ft_strlen(src, 2) + 1);
	if (dst == NULL)
		return (NULL);
	while (i < ft_strlen(src, 1) && src[i] != '\n')
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
	if (s == NULL)
		return (NULL);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\0' || s[i + 1] == '\0')
	{
		free(s);
		return (NULL);
	}
	str = (char *)malloc(ft_strlen(s, 1) - i + 1);
	if (str == NULL)
		return (NULL);
	while (j < (ft_strlen(s, 1) - i))
	{
		str[j] = s[i + j + 1];
		j++;
	}
	str[j] = '\0';
	free(s);
	return (str);
}

int	ft_count(char *p)
{
	int	i;

	i = 0;
	while (p[i] != '\n' && p[i] != '\0')
		i++;
	return (i);
}

char	*ft_getp(int fd, char *getp)
{
	int	readed;
	int	i;
	char	*buff;
	
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!buff)
		return (NULL);
	readed = read(fd, buff, BUFFER_SIZE);
	if (readed == 0 || getp == NULL)
	{
		free(buff);
		return (getp);
	}
	while (readed >= 0)
	{
		buff[readed] = '\0';
		getp = ft_strjoin(getp, buff);
		i = ft_count(getp);
		if (getp[i] == '\n' || ((readed == 0) && getp[i] == '\0'))
		{
			free(buff);
			return (getp);
		}
		readed = read(fd, buff, BUFFER_SIZE);
	//	printf("getp = %s\n", getp);
	}
	free(buff);
	return (NULL);
}

char	*get_next_line(int fd)
{
	int	i;
	static	t_stash	p[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0))
		return (NULL);
	if (p[fd].p == NULL)
	{
		p[fd].p = malloc(sizeof(char));
		p[fd].p[0] = '\0';
	}
	i = ft_count(p[fd].p);
	if (p[fd].p[i] == '\n' ||  p[fd].p[i] == '\0')
	{
		p[fd].p = ft_getp(fd, p[fd].p);
		p[fd].nline = ft_strlcpy(p[fd].nline, p[fd].p);
		p[fd].p = ft_a(p[fd].p);
		free(p[fd].buffer);
		if (p[fd].p == NULL && p[fd].nline[0] == '\0')
		{
			free(p[fd].nline);
			p[fd].nline = NULL;
			return (p[fd].nline);
		}
		return (p[fd].nline);
	}
	return (NULL);
}
/*
int	main()
{
	int	fd;
	int	i;
	char	*line;

	i = 0;
	fd = open("./gnlTester/files/big_line_no_nl", O_RDONLY);
//	line = get_next_line(fd);
	while (i < 5)
	{
	//	printf("%s", line);
	//	printf("%s    %d     \n",line,i);
		line = get_next_line(fd);
		printf("%s",line);
		if (line != NULL)
			free(line);
		i++;
	}
}*/

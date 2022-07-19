/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 23:51:32 by skrairab          #+#    #+#             */
/*   Updated: 2022/07/19 22:52:54 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_count(char *str, t_stash p)
{	
	int				i;

	i = p.start;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

void	struct_int(int fd, t_stash *p)
{
	if (p[fd].p == NULL)
	{
		p[fd].p = malloc(sizeof(char));
		p[fd].p[0] = '\0';
		p[fd].start = 0;
		p[fd].readed = 0;
	}
}

char	*ft_readed(int readed, char *getp, char *buff)
{
	if (readed == 0 || getp == NULL)
	{
		free(buff);
		return (getp);
	}
	return (NULL);
}

char	*ft_getp(int fd, char *getp, t_stash p)
{
	int		i;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!buff)
		return (NULL);
	p.readed = read(fd, buff, BUFFER_SIZE);
	if (ft_readed(p.readed, getp, buff))
		return (getp);
	while (p.readed >= 0)
	{
		buff[p.readed] = '\0';
		getp = ft_strjoin(getp, buff);
		i = ft_count(getp, p);
		if (getp[i] == '\n' || ((p.readed == 0) && getp[i] == '\0'))
		{
			p.start = i;
			free(buff);
			return (getp);
		}
		p.readed = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (NULL);
}

char	*get_next_line(int fd)
{
	int				i;
	static t_stash	p[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0))
		return (NULL);
	struct_int(fd, p);
	i = ft_count(p[fd].p, p[fd]);
	if (p[fd].p[i] == '\n' || p[fd].p[i] == '\0')
	{
		p[fd].p = ft_getp(fd, p[fd].p, p[fd]);
		p[fd].nline = ft_strlcpy(p[fd].nline, p[fd].p);
		p[fd].p = ft_a(p[fd].p);
		free(p[fd].buffer);
		if (p[fd].p == NULL && p[fd].nline[0] == '\0')
		{
			free(p[fd].nline);
			return (p[fd].nline = NULL);
		}
		return (p[fd].nline);
	}
	return (NULL);
}

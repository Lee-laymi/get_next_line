/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:37:09 by skrairab          #+#    #+#             */
/*   Updated: 2022/07/07 23:54:01 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stash
{
	char	*buffer;
	char	*p;
	char	*nline;
	int		fd;
	int		readed;
	int		start;
}			t_stash;

char	*get_next_line(int fd);
size_t	ft_strlen(char *s, int mode);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strlcpy(char *dst, char *src);
char	*ft_a(char *s);
int		ft_count(char *str, int fd);
void	struct_int(int fd, t_stash *p);
char	*ft_readed(int readed, char *getp, char *buff);
char	*ft_getp(int fd, char *getp, t_stash p);
char	*get_next_line(int fd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrairab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:37:09 by skrairab          #+#    #+#             */
/*   Updated: 2022/06/30 22:01:23 by skrairab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef	BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

typedef struct s_stash
{
	char	*buffer;
	char	*p;
//	int	start;
	char	*nline;
}			t_stash;


char	*get_next_line(int fd);




#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 17:26:06 by qtran             #+#    #+#             */
/*   Updated: 2018/02/20 18:00:01 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
int		get_line(char *str, char **remainder)
{
			
}*/

int		get_next_line(const int fd, char **line)
{
	int n;
	char *buf;
	char		*tmp;
	static int	count;
	static char *remainder;
	static char *line_cur;

	if (!(buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))) && !buf)
			return (-1);
	while ((n = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[n] = '\0';
		if (count++ == 0 || remainder == NULL)
			remainder = ft_strdup(buf);
		tmp = ft_strchr(remainder, '\n');
		if (tmp == NULL)
		{
			if (line_cur == NULL)
				line_cur = ft_strnew(1);
			line_cur = ft_strjoin(line_cur, remainder);
			continue;
		}
		else
		{
			*line = ft_strjoin(line_cur, ft_strsub(remainder, 0, tmp - remainder));
			remainder = ft_strsub(remainder, tmp - remainder + 1, ft_strlen(remainder) - (tmp - remainder));
			free(line_cur);
			line_cur = NULL;
			return (1);	
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:20:40 by qtran             #+#    #+#             */
/*   Updated: 2018/02/21 17:46:37 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	static int count;
	int n;
	int d = 0, i = 0;
	char *buf;
	char *tmp ;
	static char *res, **tab;

	buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	res = ft_strnew(1);
	if (count == 0) {
	while ((n = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[n] = '\0';
		i = 0;
		while (buf[i] != '\0')
		{
			if (buf[i] == '\n')
				d++;
			i++;
		}
		tmp = ft_strjoin(res, buf);
		free(res);
		res = tmp;
	}
	
	tab = (char**)malloc(sizeof(char*) * (d + 1));
	tab[d] = NULL;
	tab = ft_strsplit(res, '\n'); 
	}
	if (tab[count] != NULL)
	{
		*line = tab[count++];
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:37:30 by qtran             #+#    #+#             */
/*   Updated: 2017/12/14 14:57:16 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char    *ft_strncat(char *s1, const char *s2, int n)
{
    int i;
    int j;
    
    i = 0;
    while (s1[i] != '\0')
        i++;
    j = 0;
    while (s2[j] != '\0' && j < n)
    {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
    return (s1);
}

char	*ft_cpy_to_buf(int fd)
{
	char	*buf_tmp;
	char	*buf;
	int		n;
	int		len;

	if (!(buf_tmp = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1)))
			|| !buf_tmp)
		return (NULL);
	len = 0;
	while ((n = read(fd, buf_tmp, BUFF_SIZE)) > 0)
	{
		len += n;
	}
	if (!(buf = (char *)malloc(sizeof(char) * (len + 1))) || !buf)
		return (NULL);
	buf[len] = '\0';
	while ((n = read(fd, buf_tmp, BUFF_SIZE)) > 0)
	{
		ft_strncat(buf, buf_tmp, n);
	}
	free(buf_tmp);
	return (buf);
}

int		get_next_line(int fd, char **line)
{
	return (1);
}

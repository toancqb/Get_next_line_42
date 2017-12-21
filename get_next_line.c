/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:48:41 by qtran             #+#    #+#             */
/*   Updated: 2017/12/21 15:12:46 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_to_stack(t_list *st, char *buf, int size)
{
	char	*str;
	int		i;
	int		m;
	t_list *elem;

	str = ft_strchr(buf, '\n');
	m = 0;
	while (str != NULL)
	{
		elem = ft_stack_init_elem(ft_strsub(buf, 0, str - buf), str - buf);
		ft_stack_push(st, elem);
		ft_stack_push(ft_stack_init_elem("__\n__", 5));
		m = str - buf;
		str = ft_strchr(ft_strsub(buf, m, size - str + buf));
	}
	elem = ft_stack_init_elem(ft_strsub(buf, m, size - m), size - m);
	ft_stack_push(st, elem);
	if (!ft_strchr(ft_strsub(buf, m, size - m), '\n'))
	{
		return (3);
	}
	if (ft_strchr(buf, EOF))
	{	
		ft_stack_push(ft_stack_init_elem(EOF, 1));
		return (2);
	}
	return (1);
}
/*
int	ft_stack_to_line(t_list *st, char **line)
{
	
}*/

int		get_next_line(const int fd, char **line)
{
	int				n;
	static t_list	*st;
	int				len;
	char			*buf_tmp;

	if (!(buf_tmp = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))) || !buf_tmp)
		return (-1);
	i = 0;
	while ((n = read(fd, buf_tmp, BUFF_SIZE)) > 0)
	{
		buf_tmp[n] = '\0';
		if (!ft_to_stack(st, buf_tmp, n) || !(n = ft_stack_to_line(st, line)) || !n)
			return (-1);
		else if (n == 2)
			return (0);
		else if (n == 3)
			continue;
	}
	return (1);
}

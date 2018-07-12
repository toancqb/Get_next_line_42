/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 16:20:35 by qtran             #+#    #+#             */
/*   Updated: 2018/07/02 16:17:26 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*get_current_fd(t_list **st, const int fd)
{
	t_list *tmp;

	tmp = *st;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(st, tmp);
	tmp = *st;
	return (tmp);
}

int		ft_strcpy_ch(char **line, char *buf, char c)
{
	int i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == c)
			break ;
		i++;
	}
	*line = (char*)malloc(sizeof(char) * (i + 1));
	(*line)[i] = '\0';
	*line = ft_strncpy(*line, buf, i);
	return (i);
}

void	ft_next_n_char(char **str, unsigned int n)
{
	char *tmp;

	tmp = *str;
	*str = ft_strdup(tmp + n);
	ft_strdel(&tmp);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	static t_list	*st;
	char			buf[BUFF_SIZE + 1];
	t_list			*cur;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	cur = get_current_fd(&st, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		cur->content = ft_strjoin(cur->content, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(cur->content))
		return (0);
	ret = ft_strcpy_ch(line, cur->content, '\n');
	if (ret < (int)ft_strlen(cur->content))
		ft_next_n_char((char**)&cur->content, ret + 1);
	else
		ft_strclr(cur->content);
	return (1);
}

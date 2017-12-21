/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:48:03 by qtran             #+#    #+#             */
/*   Updated: 2017/12/21 14:47:14 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
#include "libft/libft.h"
# define BUFF_SIZE 42

int		ft_to_stack(t_list *st, char *buf, int size);

int		get_next_line(const int fd, char **line);

#endif

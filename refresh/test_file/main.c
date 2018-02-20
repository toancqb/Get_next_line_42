/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 15:10:21 by qtran             #+#    #+#             */
/*   Updated: 2018/02/20 14:52:17 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../get_next_line.h"
#include <fcntl.h>

int		main(int argc, char *argv[])
{
	char	*buf;
	int		i;
	int		fd;
	int		id;

	//if (!(buf = (char *)malloc(sizeof(char) * (BUF_SIZE + 1)) && !buf)
	//		return (-1);
	if (!(fd = open(argv[1], O_RDONLY)) && !fd)
		return (-1);
	while (get_next_line(fd, &buf) == 1)
	{
		printf("line %d: %s\n", id, buf);
		id++;
	}
	return (0);
}

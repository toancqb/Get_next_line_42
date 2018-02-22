
#include "get_next_line.h"

int	get_next_line(int const fd, char **line)
{
	int		ret;
	static char	*line_cur;
	char		buf[BUFF_SIZE + 1];
	
	if (!line_cur)
		line_cur = ft_strnew(1);
	*line = ft_strnew(1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		line_cur = ft_strjoin(line_cur, buf);	
		if (ft_strchr(buf, '\n'))
			break;
	}
	if (ret < BUFF_SIZE && !ft_strlen(line_cur))
		return (0);
	*line = ft_strsub(line_cur, 0, ft_strchr(line_cur, '\n') - line_cur);
	if (ft_strchr(line_cur, '\n') - line_cur == ft_strlen(line_cur))
	{
		free(line_cur);
		line_cur = NULL;
	}
	else
		line_cur += ft_strchr(line_cur, '\n') - line_cur + 1;
	return (1);
}

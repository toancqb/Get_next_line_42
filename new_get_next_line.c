
#include "get_next_line.h"

char	*ft_strjoin_new(char *line_cur, char *buf)
{
	int		len;
	char	*s;
	int		i;

	if (!line_cur)
	{
		len = ft_strlen(buf);
		line_cur = (char*)malloc(sizeof(char) * (len + 1));
		line_cur[len] = '\0';
		ft_strcpy(line_cur, buf);
		return (line_cur);
	}
	else
	{
		len = ft_strlen(buf) + ft_strlen(line_cur);
		s = (char*)malloc(sizeof(char) * (len + 1));
		s[len] = '\0';
		i = 0;
		while (line_cur[i] != '\0')
		{
			s[i] = line_cur[i];
			i++;
		}
		len = 0;
		while (buf[len] != '\0')
		{
			s[i + len] = buf[len];
			len++;
		}
		free(line_cur);
		return (s);
	}
}

int	get_next_line(int const fd, char **line)
{
	int		ret;
	static char	*line_cur;
	char		buf[BUFF_SIZE + 1];
	
	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		line_cur = ft_strjoin_new(line_cur, buf);	
		if (ft_strchr(buf, '\n'))
			break;
	}
	if (ret < BUFF_SIZE && !ft_strlen(line_cur))
		return (0);
	*line = ft_strsub(line_cur, 0, ft_strchr(line_cur, '\n') - line_cur);
	if ((int)(ft_strchr(line_cur, '\n') - line_cur) >=
			(int)ft_strlen(line_cur))
	{
		free(line_cur);
		line_cur = NULL;
	}
	else
		line_cur += ft_strchr(line_cur, '\n') - line_cur + 1;
	return (1);
}

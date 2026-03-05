#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*next;
	int			read_byte;
	static char	*stash;
	char		*line;
	int			len;
	char		buffer[BUFFER_SIZE + 1];

	len = 0;
	next = ft_strchr(stash, '\n');
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while (next == NULL)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
			return (NULL);
		if (read_byte == 0)
			break ;
		buffer[read_byte] = '\0';
		stash = ft_strjoin(stash, buffer);
		next = ft_strchr(stash, '\n');
	}
	if (!stash)
		return (NULL);
	if (next)
		len = (next - stash) + 1;
	else
		len = ft_strlen(stash);
	line = ft_substr(stash, 0, len);
	stash = ft_substr(stash, len, ft_strlen(stash) - len);
    return (line);
}

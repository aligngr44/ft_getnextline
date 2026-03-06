#include "get_next_line.h"

static char	*replace_stash(char *stash, char *new_value)
{
	free(stash);
	return (new_value);
}

char	*get_next_line(int fd)
{
	char		*next;
	int			read_byte;
	static char	*stash;
	char		*line;
	int			len;	
	char		buffer[BUFFER_SIZE + 1];

	len = 0;
	if (!stash)
   		 stash = ft_strdup("");
	next = ft_strchr(stash, '\n');
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while (next == NULL)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
		if (read_byte == 0)
			break ;
		buffer[read_byte] = '\0';
		stash = replace_stash(stash, ft_strjoin(stash, buffer));
		if (!stash)
			return (NULL);
		next = ft_strchr(stash, '\n');
	}
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (next)
		len = (next - stash) + 1;
	else
		len = ft_strlen(stash);
	line = ft_substr(stash, 0, len);
	next = ft_substr(stash, len, ft_strlen(stash) - len);
	free(stash);
	stash = next;
	return (line);
}

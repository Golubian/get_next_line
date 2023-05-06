#include "get_next_line.h"

// TODO: handle EOF
char *get_next_line(int fd)
{
	static struct fd_pos_bank *head;
	struct fd_pos_bank *current;
	char *buffer;
	char *line;
	int i;

	current = get_stored_from_fd(fd, &head);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (i < BUFFER_SIZE)
	{
		read(fd, buffer, 1);
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
		if (buffer[0] == '\n')
			break ;
		current->pos++;
		i++;
	}
	free(buffer);
	return (line);
}
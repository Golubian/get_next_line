#include "get_next_line.h"

struct fd_pos_bank *get_stored_from_fd(int fd, struct fd_pos_bank *head)
{
	struct fd_pos_bank *current;

	current = head;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	current = malloc(sizeof(struct fd_pos_bank));
	current->fd = fd;
	current->pos = 0;
	current->next = NULL;
	return (current);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}
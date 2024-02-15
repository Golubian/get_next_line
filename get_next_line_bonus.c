/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:16:55 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/15 09:58:55 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	while (n > 0 && s)
	{
		((char *) s)[n - 1] = 0;
		n--;
	}
}

static void	empty_buffer(char *buffer)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[i] = 0;
		i++;
	}
}

static t_fd_bank	*read_from_buffer(t_fd_bank **head, int fd)
{
	t_fd_bank	*bank;
	size_t		bytes_read;

	if (!head || !ft_lstmatch(head, fd))
		bank = ft_lstaddback(head, fd);
	else
		bank = ft_lstmatch(head, fd);
	if (!bank)
		return (NULL);
	if ((bank -> buf) - (bank -> buf_start) == BUFFER_SIZE)
	{
		bank->buf = bank->buf_start;
		empty_buffer(bank->buf_start);
		bytes_read = read(fd, bank -> buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (empty_buffer(bank->buf_start), ft_lstrem(head, fd), NULL);
	}
	return (bank);
}

static char	*generate_line(t_fd_bank **head, int fd)
{
	char		*line;
	t_fd_bank	*bank;

	line = NULL;
	bank = read_from_buffer(head, fd);
	while (bank && (*(bank->buf) != '\n' && *(bank->buf) != '\0'))
	{
		line = ft_strjoin_free(line, *(bank->buf));
		if (!line)
			return (NULL);
		(bank->buf)++;
		if ((bank -> buf) - (bank -> buf_start) == BUFFER_SIZE)
			bank = read_from_buffer(head, fd);
	}
	if (bank && *(bank->buf) == '\0')
		return (ft_lstrem(head, fd), line);
	if (bank && *(bank->buf) == '\n')
	{
		line = ft_strjoin_free(line, '\n');
		(bank->buf)++;
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static t_fd_bank	*head;
	char				*result;

	result = NULL;
	if (fd < 0 || read(fd, result, 0) < 0)
	{
		if (ft_lstmatch(&head, fd))
			ft_lstrem(&head, fd);
		return (NULL);
	}
	if (!head)
		head = NULL;
	result = generate_line(&head, fd);
	return (result);
}

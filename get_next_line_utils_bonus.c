/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:17:06 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/15 10:00:19 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*re;
	size_t	n;

	n = nmemb * size;
	re = malloc(n);
	if (!re)
		return (NULL);
	while (n > 0 && re)
	{
		((char *) re)[n - 1] = 0;
		n--;
	}
	return (re);
}

char	*ft_strjoin_free(char *str, char c)
{
	char	*new;
	size_t	size;

	if (!str)
		str = ft_calloc(1, sizeof(char));
	if (!str)
		return (NULL);
	size = 0;
	while (*str)
	{
		size++;
		str++;
	}
	str -= size;
	new = ft_calloc(1, size + 2);
	new[size] = c;
	while (size > 0)
	{
		new[size - 1] = str[size - 1];
		size--;
	}
	free(str);
	return (new);
}

t_fd_bank	*ft_lstmatch(t_fd_bank	**head, int fd)
{
	t_fd_bank	*current;

	if (!*head)
		return (NULL);
	current = *head;
	while (current)
	{
		if (current -> fd == fd)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	ft_lstrem(t_fd_bank **head, int fd)
{
	t_fd_bank	*current;
	t_fd_bank	*to_free;

	current = *head;
	if (current -> fd == fd)
	{
		free(current->buf_start);
		*head = current->next;
		ft_bzero(current, sizeof(t_fd_bank));
		free(current);
		return ;
	}
	while (current->next)
	{
		if (current->next->fd == fd)
		{
			to_free = current->next;
			free(to_free->buf_start);
			current->next = to_free->next;
			ft_bzero(to_free, sizeof(t_fd_bank));
			return (free(to_free));
		}
		current = current -> next;
	}
	return ;
}

t_fd_bank	*ft_lstaddback(t_fd_bank **head, int fd)
{
	t_fd_bank	*new;
	t_fd_bank	*current;

	new = malloc(sizeof(t_fd_bank));
	if (!new)
		return (NULL);
	new -> fd = fd;
	new -> buf = ft_calloc(1, sizeof(char) * (BUFFER_SIZE + 1));
	new -> buf_start = new -> buf;
	new -> buf += BUFFER_SIZE;
	new -> next = 0;
	if (!(new -> buf_start))
		return (free(new), NULL);
	if (!(*head))
		*head = new;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	return (new);
}

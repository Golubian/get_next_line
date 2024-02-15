/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:13:40 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/15 09:59:14 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_fd_bank
{
	int					fd;
	char				*buf;
	char				*buf_start;
	struct s_fd_bank	*next;
}	t_fd_bank;

char		*get_next_line(int fd);
void		ft_bzero(void *s, size_t n);

char		*ft_strjoin_free(char *str, char c);

t_fd_bank	*ft_lstmatch(t_fd_bank	**head, int fd);
t_fd_bank	*ft_lstaddback(t_fd_bank **head, int fd);
void		ft_lstrem(t_fd_bank **head, int fd);

#endif
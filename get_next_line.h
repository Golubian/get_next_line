#ifndef GET_NEXT_LINE_H
	#define GET_NEXT_LINE_H
	#define BUFFER_SIZE 32

	#include <unistd.h>
	struct fd_pos_bank
	{ 
		int fd;
		size_t pos;
		struct fd_pos_bank *next;
	};

	char	*ft_strjoin(char const *s1, char const *s2);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboehm <aboehm@42adel.org>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:22:24 by aboehm            #+#    #+#             */
/*   Updated: 2021/10/06 01:42:20 by aboehm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *appendline(char **s)
{
	
}

char *get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*s[4096]; //set to file descriptor size??
	char		*tmp;
	int			nbytes;

	if (fd < 0)
		return (NULL);
	nbytes = read(fd, buffer, BUFFER_SIZE);
	while(nbytes)
	{
		printf("%d", fd);
		buffer[nbytes] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(s[fd], buffer);
			free(s[fd]);
			s[fd]= tmp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
		nbytes = read(fd, buffer, BUFFER_SIZE);
	}
	buffer[nbytes] = '\0';
	return (appendline(char **s));
}


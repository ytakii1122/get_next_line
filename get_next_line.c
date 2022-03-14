/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:30:53 by ytakii            #+#    #+#             */
/*   Updated: 2022/03/14 17:50:38 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"
#include <stdio.h>

/*
char	*ft_read(fd)
{
	char    *reading;
	char    buf[BUF_SIZE + 1];
	char    ret;

	while (1)
	{
		ret = read(fd, buf, BUF_SIZE);
		if (ret < 0)
			return (NULL);
		buf[ret] = '\0';
		break; 
	}   
	reading = &buf[0];
	return (reading);
}
*/

char *get_next_line(int fd)
{
	char	*line;
	char	*buf;
	char	read_size;
	//char	i;
	char	memo;

	read_size = 1;
	buf = 0;
	if (fd == '\0')
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUF_SIZE + 1));
	while (read_size != 0)
	{
		read_size = read(fd, buf, BUF_SIZE);
		if (read_size < 0)
			return (NULL);
		buf[read_size] = '\0';
		//printf("%s\n", buf);
		i = ft_strchr(buf, '\n');

		if (i == NULL)// break
			memo = memo + buf;
			break;
		else
			memo = memo + buf;
	}
	//printf("%s\n",i);
	//line = &buf[0];
	return (buf);
}

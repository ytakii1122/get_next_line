/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:30:53 by ytakii            #+#    #+#             */
/*   Updated: 2022/03/22 12:22:11 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"
# include <stdio.h>
//BUFFER SIZE 4
				//abcde\nefg\n buf=4+1size 
char	*ft_read(int fd, char *read_line)
{
	size_t    read_size;
	char	*buf;
	char	*tmp;

	//buf = NULL;
	buf = (char *)malloc(sizeof(char) * (BUF_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	read_size = 1;
	read_line = "";
	while (read_size > 0)
	{
		read_size = read(fd, buf, BUF_SIZE);
		if (read_size < 0)
		{
			free(buf);
			return (NULL);
		}		
		buf[read_size] = '\0';
		/*if (read_line == NULL)
		{
			read_line = buf;
			read_line[read_size] = '\0';
			//printf("%s\n",read_line);
		}else*/
		read_line = ft_strjoin(read_line, buf);
		/*if (ft_strchr(read_line, '\n'))
			break;*/
	}
	free(buf);
	return (read_line);
}
/*
char	ft_line_strchr(**read_line, **line )
{
	
}
*/
/*char	ft_free(buf)
{

}
*/
char	*get_next_line(int fd)
{
	char	*line;
	//char	*buf;
	//char	read_size;
	//char	i;
	char	*read_line;
	char	*save;

	line = NULL;
	read_line = NULL;
	if (fd == '\0')
		return (NULL);
	read_line = ft_read(fd, read_line);
	printf("%s\n",read_line);
	/*while (read_size != 0)
	{
		read_size = read(fd, buf, BUF_SIZE);
		if (read_size < 0)
			return (NULL);
		buf[read_size] = '\0';
	}*/

	//line = &buf[0];	
	//line = ft_line_cpy(&read_line, &line);
	return (line);
}

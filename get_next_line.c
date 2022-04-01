/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:30:53 by ytakii            #+#    #+#             */
/*   Updated: 2022/03/29 18:30:01 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_free(char **dst, char *src)
{
	free(*dst);
	*dst = src;
}

char	*ft_read(int fd, char *read_line, int *flag)
{
	size_t	read_size;
	char	*buf;
	char	*tmp;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	read_size = 1;
	while (read_size > 0 /*|| !ft_strchr(read_line, '\n')*/)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
		{
			ft_free(&buf, NULL);
			return (NULL);
		}
		if (read_size == 0)
			*flag = 0;
		buf[read_size] = '\0';
		if (read_line == NULL)
		{
			tmp = ft_strjoin("", buf);
			ft_free(&read_line, tmp);//read_line = tmp;
		}
		else
		{	
			tmp = ft_strjoin(read_line, buf);
			ft_free(&read_line, tmp);//read_line = tmp;
		}
		if (ft_strchr(read_line, '\n'))
			break ;
	}
	ft_free(&buf, NULL);
	return (read_line);
}

char	*ft_line_cpy(char **read_line, char **line )
{
	char	*line_before_n;
	size_t	line_size;
	size_t	i;

	i = 0;
	line_before_n = ft_strchr(*read_line, '\n');
	line_size = ft_strlen(*read_line) - ft_strlen(line_before_n);
	*line = (char *)malloc(sizeof(char *) * (line_size + 1));
	if (line < 0)
		return (NULL);
	while (i < line_size)
	{
		(*line)[i] = (*read_line)[i];
		i++;
	}
	(*line)[i] = '\0';
	return (*line);
}

/*
char	*ft_line_cpy(char *read_line)
{
	size_t	count;
	size_t	i;
	char	*return_line;

	if (read_line == '\0')
		return (NULL);
	count = ft_strlen(read_line) - ft_strlen(ft_strchr(read_line, '\n'));

	return_line = (char *)malloc(sizeof(char *) * (count + 1));
	if (return_line < 0)
		return(NULL);
	i = 0;
	while (i < count)
	{
		return_line[i] = read_line[i];
		i++;
	}	
	return_line[i] = '\0';
	//read_line = ft_strchr(read_line, '\n');
	return (return_line);
}
*/
char	*ft_save(char *line, char *read_line)
{
	char	save_size;
	char	*save;
	size_t	i;

	i = 0;
	save_size = ft_strlen(read_line) - ft_strlen(line);
	save = (char *)malloc(sizeof(char *) * (save_size + 1));
	if (save == NULL)
		return (NULL);
	while (read_line[i] != '\0')
	{
		save[i] = read_line[ft_strlen(line) + 1 + i];
		i++;
	}
	//printf("%s\n",save);
	free(read_line);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*read_line;
	int	flag;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > SIZE_MAX)
		return (NULL);
	flag = 1;
	read_line = ft_read(fd, read_line, &flag);
	if (read_line == NULL)
		return (NULL);
	line = ft_line_cpy(&read_line, &line);
	//line = ft_line_cpy(read_line);
	if (line == NULL)
		return (NULL);
	read_line = ft_save(line, read_line);
	if (read_line == NULL)
		return (NULL);
	if (flag == 0 && line[0] =='\0' && read_line[0] == '\0')
	{
		ft_free(&read_line, NULL);
		return (NULL);
	}
	return (line);

}

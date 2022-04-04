/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:30:53 by ytakii            #+#    #+#             */
/*   Updated: 2022/04/03 19:18:05 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_free(char **dst, char *src)
{
	free(*dst);
	*dst = src;
}

char	*save_loaded_line(int fd, char *save)
{
	char	*buf;
	char	*tmp;
	ssize_t	read_size;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	read_size = 1;
	while(read_size > 0 || ft_strchr(save, '\n')== NULL)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
		{
			ft_free(&buf, NULL);
			return (NULL);
		}
		buf[read_size] = '\0';
		if (save == NULL && buf == NULL)
			save = ft_strdup("");
		else if (save == NULL)
			save = ft_strdup(buf);
		else if (buf == NULL)
			save = ft_strdup(save);
		/*{
			tmp = ft_strjoin("", buf);
			ft_free(&save, tmp);//read_line = tmp;
		}*/
		else
		{	
			tmp = ft_strjoin(save, buf);
			ft_free(&save, tmp);//read_line = tmp;
		}

		/*if (save == NULL)
			save = "";
		printf("%s",buf);
		//ft_free(&tmp, NULL);
		tmp = ft_strjoin(save, buf);
		ft_free(&save, NULL);
		save = tmp;
		//printf("%s",save);
		*/
		//if (ft_strchr(save, '\n'))
		//		break ;
	}
	ft_free(&buf, NULL);
	return (save);
}

/*
char	*ft_read(int fd, char *read_line, int *flag)
{
	size_t	read_size;
	char	*buf;
	char	*tmp;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	read_size = 1;
	while (read_size > 0 || !ft_strchr(read_line, '\n'))
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
}*/
/*
char	*ft_line_cpy(char **read_line, char **line )
{
	char	*line_before_n;
	size_t	line_size;
	size_t	i;

	i = 0;
	if (ft_strchr(*read_line, '\n') == NULL)
		line_size = ft_strlen(*read_line);
	else
	{
	line_before_n = ft_strchr(*read_line, '\n');
	line_size = ft_strlen(*read_line) - ft_strlen(line_before_n);
	}
	*line = (char *)malloc(sizeof(char) * (line_size + 1));
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
*/

char	*get_new_line(char *save)
{
	size_t	i;
	char	*return_line;
	
	i = 0;
	if (save == '\0')
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	return_line = (char *)malloc(sizeof(char) * (i + 1));//'\n'+'\0'
	if (return_line == NULL)
		return(NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		return_line[i] = save[i];
		i++;
	}	
	return_line[i] = '\0';
	//printf("return_line:%s",return_line);
	return (return_line);
}
char	*ft_save_update(char *save)
{
	char	*save_update;
	size_t	save_size;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	save_size = ft_strlen(save);	
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		ft_free(&save, NULL);
		return (NULL);
	}
	save_update = (char *)malloc(sizeof(char) * (save_size - (i + 1) + 1)); //+1-1
	if (save_update == NULL)
	{
		ft_free(&save, NULL);
		return (NULL);
	}
	while (save[i + 1 + j] != '\0')
	{
		save_update[j] = save[i + 1 + j];
		j++;
	}
	ft_free(&save, NULL);
	return (save_update);
}
/*
char	*ft_save(char *line, char *read_line)
{
	char	save_size;
	char	*save;
	size_t	i;

	i = 0;
	save_size = ft_strlen(read_line) - ft_strlen(line);
	save = (char *)malloc(sizeof(char) * (save_size + 1));
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
*/
char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = save_loaded_line(fd, save);
	//printf("%s",save);
	if (save == NULL)
		return (NULL);
	line = get_new_line(save);
	//line = ft_line_cpy(read_line);
	//line = ft_line_cpy(&save, &line);
	//printf("line: %s\n",line);
	if (line == NULL)
		return (NULL);
	//save = ft_save(line, save);
	save = ft_save_update(save);
	//printf("save_update: %s\n",save);
	if (save == NULL)
		return (NULL);
/*	if (save == 0 && line[0] =='\0' && save[0] == '\0')
	{
		ft_free(&save, NULL);
		return (NULL);
	}*/
	//printf("line :%s",line);
	return (line);

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:30:53 by ytakii            #+#    #+#             */
/*   Updated: 2022/04/08 14:20:02 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	*ft_free_return(char *dst)
{	
	free(dst);
	dst = NULL;
	return (NULL);
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
	while (read_size > 0 && ft_strchr(save, '\n') == NULL)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
			return (ft_free_return(buf));
		buf[read_size] = '\0';
		if (save == NULL)
			save = ft_strdup("");
		tmp = ft_strjoin(save, buf);
		free(save);
		save = tmp;
		if (read_size == 0)
			break ;
	}
	free(buf);
	buf = NULL;
	return (save);
}

char	*get_new_line(char *save)
{
	size_t	i;
	char	*return_line;

	i = 0;
	if (save[i] == '\0')
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	return_line = (char *)malloc(sizeof(char) * (i + 1));
	if (return_line == NULL)
		return (NULL);
	return_line[i] = '\0';
	while (i)
	{
		i--;
		return_line[i] = save[i];
	}
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
		return (ft_free_return(save));
	save_update = (char *)malloc(sizeof(char) * (save_size - (i + 1) + 1));
	if (save_update == NULL)
		return (ft_free_return(save));
	while (save[i + 1 + j] != '\0')
	{
		save_update[j] = save[i + 1 + j];
		j++;
	}
	save_update[j] = '\0';
	free(save);
	save = NULL;
	return (save_update);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = save_loaded_line(fd, save);
	if (save == NULL)
		return (NULL);
	line = get_new_line(save);
	save = ft_save_update(save);
	return (line);
}

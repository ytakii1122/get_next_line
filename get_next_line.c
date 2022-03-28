/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:30:53 by ytakii            #+#    #+#             */
/*   Updated: 2022/03/28 23:08:42 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"
# include <stdio.h> 
char	*ft_read(int fd, char *read_line)
{
	size_t    read_size;
	char	*buf;
	char	*tmp;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	read_size = 1;
	while (read_size > 0 /*|| !ft_strchr(read_line, '\n')*/)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0)
		{
			free(buf);
			return (NULL);
		}		
		buf[read_size] = '\0';
		if (read_line == NULL)
		{
			tmp = ft_strjoin("", buf);
			free(read_line);
			read_line = NULL;
			read_line = tmp;
		}
		else
		{	
			tmp = ft_strjoin(read_line, buf);
			free(read_line);
			read_line = NULL;
			read_line = tmp;
		}
		//printf("%s\n",read_line);
		if (ft_strchr(read_line, '\n'))
			break;
	}
	//printf("%s\n",read_line);
	free(buf);
	buf = NULL;
	return (read_line);
}

char	*ft_line_cpy(char **read_line, char **line )
{
	char	line_lengh;
	char	*line_before_n;
	size_t	line_size;
	//char	*return_line;
	size_t	i;


	i = 0;
	line_lengh = ft_strlen(*read_line);
	line_before_n = ft_strchr(*read_line, '\n');
	line_size = line_lengh - ft_strlen(line_before_n);
	*line = (char *)malloc(sizeof(char *) * (line_size + 1));
	if (line < 0)
	{
		//ft_free;
		return (NULL);
	}
	while (i < line_size)
	{
		(*line)[i] = (*read_line)[i];	
		/***line = **read_line;
		(**line)++;
		(**read_line)++;*/
		i++;
		//printf("%s\n",*line);
	}
	(*line)[i] = '\0';
	//**line = '\0';
	
	//printf("%s\n", *line); 
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
	//printf("%s\n",read_line);
	count = ft_strlen(read_line) - ft_strlen(ft_strchr(read_line, '\n'));

	//printf("%zu\n",count);
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
	//printf("%s\n", read_line);
	return (return_line);
}
*/
char	*ft_save(char *line, char *read_line)
{
	char	save_size;
	char	*save;
	//char	*tmp;
	size_t	i;
	//size_t	j;
	
	i = 0;
	//j = 0;
	//printf("%s\n",line);
	//printf("%s\n",read_line);
	save_size = ft_strlen(read_line) - ft_strlen(line);
	//printf("%d\n",save_size);
	save = (char *)malloc(sizeof(char *) * (save_size + 1));
	//printf("%s\n",read_line);
	//read_line = ft_strchr(read_line, '\n');
	/*while (read_line[i] != '\n')
		i++;
	i++;*/
	//printf("%s\n",read_line);
	//printf("%zu\n", i);
	while (read_line[i] != '\0')
	{
		save[i] = read_line[ft_strlen(line) + 1 + i];
		i++;
	}
	//printf("%s\n",save);	
	free(read_line);
	return(save);
}

/*void	ft_free(buf)
{

}
*/
char	*get_next_line(int fd)
{
	char	*line;
	//char	*buf;
	//char	read_size;
	//char	i;
	static char	*read_line;
	//char	*save;
	

	//printf("%s\n",read_line);
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_line = ft_read(fd, read_line);
	if (read_line == NULL)
		return (NULL);
	//printf("%s\n",read_line);
	line = ft_line_cpy(&read_line, &line);
	//printf("%s\n",line);
	//printf("%s\n",read_line);
	read_line = ft_save(line,read_line);
	//printf("%s\n",read_line);
	return (line);
}

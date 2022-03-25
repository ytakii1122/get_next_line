/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:30:53 by ytakii            #+#    #+#             */
/*   Updated: 2022/03/25 16:56:03 by ytakii           ###   ########.fr       */
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
	//char	*tmp;

	buf = (char *)malloc(sizeof(char) * (BUF_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	read_size = 1;
	read_line = "";
	while (read_size > 0 /*|| !ft_strchr(read_line, '\n')*/)
	{
		read_size = read(fd, buf, BUF_SIZE);
		if (read_size < 0)
		{
			free(buf);
			return (NULL);
		}		
		buf[read_size] = '\0';
		/*read_line = (char *)malloc(sizeof(char) * (ft_strlen(read_line) + ft_strlen(buf)) + 1);
		{
			free(buf);
			return (NULL);
		} */
		read_line = ft_strjoin(read_line, buf);
		//printf("%s\n",read_line);
		/*if (ft_strchr(read_line, '\n'))
			break;*/
	}
	//printf("%s\n",read_line);
	free(buf);
	return (read_line);
}
/*
char	*ft_line_cpy(char **read_line, char **line )
{
	char	line_lengh;
	char	*tmp;
	char	count;
	//char	*return_line;
	size_t	i;


	i = 0;
	//printf("%s\n", *read_line);
	line_lengh = ft_strlen(*read_line);
	//printf("%d\n", line_lengh);

	tmp = ft_strchr(*read_line, '\n');
	count = line_lengh - ft_strlen(tmp);
	
	
	//printf("%s\n", tmp);
	//printf("%d\n", ft_strlen(tmp));
	//while (read_line[count] != '\0' || read_line[count] == '\n')
	//	count++;
	printf("%d\n",count);



	line = (char **)malloc(sizeof(char **) * (count + 1));
	if (line < 0)
	{
		//ft_free;
		return (NULL);
	}
	while (i < count)
	{
		**line = **read_line;
		i++;
		//printf("%s\n",*line);
	}
	line[i] = '\0';
	printf("%s\n", *line); 
	return (*line);
}*/

char	*ft_line_cpy(char *read_line)
{
	size_t	count;
	size_t	i;
	char	*return_line;

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
	//printf("%s\n", return_line);
	return (return_line);
}




/*
char	ft_save(*read_line)
{


}
*/
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
	char	*read_line;
	//char	*save;

	line = NULL;
	read_line = NULL;
	if (fd == '\0')
		return (NULL);
	read_line = ft_read(fd, read_line);
	//printf("%s\n",read_line);
	line = ft_line_cpy(read_line);
	//printf("%s\n",line);
	//save = ft_save(&read_line);
	return (line);
}

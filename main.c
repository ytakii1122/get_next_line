#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

char    *save_loaded_line(int fd, char *save);

int    main(void)
{
	int        fd;
	//char    *buf;
	//static char    *save;
	char	*line;
	//int        flag;
	size_t    cnt;
	//size_t	i;

	cnt = 0;
	fd = open("sample.txt", O_RDONLY);
	//flag = 1;
	//buf = save_loaded_line(fd, save);
	//printf("buf: %s\n", buf);
	//line = get_next_line(fd);
	//printf("%s",line);
/*	line = get_next_line(fd);
	printf("[%s]",line);

	line = get_next_line(fd);
	printf("[%s]",line);

	line = get_next_line(fd);
	printf("[%s]",line);*/
/*	while (i < 2)
	{
		line = get_next_line(fd);
		printf("%s",line);
		i++;
	}*/
/*	while (1) 
	{ 
	     line = get_next_line(fd); 
	     if (line == NULL) 
	     { 
	         puts("NULL returned."); 
	         break ;
	     } 
	     printf("line[%zu]: %s", cnt, line); 
	     free(line); 
		 cnt++; 
	 }*/
	//printf("line[%zu]: %s", cnt, line); 
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			//printf("NULL returned");
			break ;
		}
		printf("%s",line);
		free(line);
		cnt++;
	}
	close(fd);
	system("leaks -q a.out");
	    return (0);
	
}

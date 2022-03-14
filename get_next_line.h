/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:06:46 by ytakii            #+#    #+#             */
/*   Updated: 2022/03/14 16:47:44 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#ifndef GET_NEXT_LINE_H 
//# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#define BUF_SIZE 100

char	*get_next_line(int fd);
char	get_next_line_utils(int fd);

//#endif

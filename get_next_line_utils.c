/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:27:00 by ytakii            #+#    #+#             */
/*   Updated: 2022/03/14 16:16:57 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include<stdio.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	j;

	j = 0;
	while (s[j] != '\0')
	{
		if (s[j] == (unsigned char) c)
			return ((char *)&s[j]);
		j++;
	}
	if (c == '\0')
		return ((char *)&s[j]);
	return (NULL);
}
/*
int main(void)
{
	char str1[] = "abcdef\nghij";
	char*q;

	q = ft_strchr(str1, '\n');
	printf("%s\n", q + 1);

	return (0);
}*/

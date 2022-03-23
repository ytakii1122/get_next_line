/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:27:00 by ytakii            #+#    #+#             */
/*   Updated: 2022/03/22 11:53:09 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include<stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*add_s1s2;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	add_s1s2 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (add_s1s2 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		add_s1s2[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		add_s1s2[i + j] = s2[j];
		j++;
	}
	add_s1s2[i + j] = '\0';
	return (add_s1s2);
}



/*
int main(void)
{
	//char str1[] = "abcdef\nghij";
	char str1[] = "";
	char*q;
	char str2[] = "1111";
	//q = ft_strchr(str1, '\n');
	
	q = strjoin(str1, str2);
	printf("%s\n", q);

	return (0);
}*/

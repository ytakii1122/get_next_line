/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytakii </var/mail/ytakii>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 21:27:00 by ytakii            #+#    #+#             */
/*   Updated: 2022/04/08 13:16:58 by ytakii           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (str == NULL)
		return (0);
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
	if (s == NULL)
		return (NULL);
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

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	j;
	char	*a;

	i = 0;
	j = 0;
	i = ft_strlen(s1);
	a = (char *)malloc(sizeof(char) * (i + 1));
	if (a == NULL)
		return (NULL);
	while (s1[j] != '\0' && j < i + 1)
	{
		a[j] = s1[j];
		j++;
	}
	a[j] = '\0';
	return (a);
}

/*
int main(void)
{
	//char str1[] = "abcdef\nghij";
	static char str1 [] = "aaaa";
	char*q;
	char str2[] = "\0";
	//q = ft_strchr(str1, '\n');
	
	q = ft_strjoin(str1, str2);
	printf("%s\n", q);

	return (0);
}*/

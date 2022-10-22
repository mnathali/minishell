/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasuo <zyasuo@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:43:52 by zyasuo            #+#    #+#             */
/*   Updated: 2021/10/07 17:43:52 by zyasuo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"
#include<stdlib.h>

static char	*ft_strndup(char *src, size_t n)
{
	char	*dup;

	dup = (char *)malloc(n + 1);
	if (!dup)
		return ((void *)0);
	dup[n] = '\0';
	return (ft_memcpy(dup, src, n));
}

static int	count_tokens(char const *s, char c)
{
	int		tokens_count;

	tokens_count = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) == 0)
		return (0);
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s++ == c)
			continue ;
		s--;
		if (*s != c)
		{
			tokens_count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (tokens_count);
}

static void	arrayclr(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

static void	fill_array(char **array, int tokens, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	while (*s == c)
		s++;
	while (i < tokens)
	{
		j = 0;
		while (*s == c)
			s++;
		while (s[j] != c && s[j])
			j++;
		array[i] = ft_strndup((char *)s, j);
		if (!array[i])
		{
			arrayclr(array);
			return ;
		}
		i++;
		s += j;
	}
}

char	**ft_split(char const *s, char c)
{
	int		tokens_count;
	char	**array;

	if (!s)
		return ((void *)0);
	tokens_count = count_tokens(s, c);
	array = (char **) malloc((tokens_count + 1) * (sizeof(char *)));
	if (!array)
		return ((void *)0);
	ft_bzero(array, (tokens_count + 1) * sizeof(char *));
	fill_array(array, tokens_count, s, c);
	return (array);
}

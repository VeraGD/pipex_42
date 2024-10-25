/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:27:26 by veragarc          #+#    #+#             */
/*   Updated: 2024/10/25 09:27:42 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_free(char **split_result)
{
	unsigned int	index;

	index = 0;
	while (split_result[index] != 0)
	{
		free(split_result[index]);
		index++;
	}
	free(split_result);
}

static unsigned int	ft_count_strs(char const *s, char c)
{
	unsigned int	counter;
	unsigned int	index;

	counter = 0;
	index = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (s[index])
			counter++;
		while (s[index] != c && s[index])
			index++;
	}
	return (counter);
}

static unsigned int	ft_size_str(char const *str, char c)
{
	unsigned int	length;

	length = 0;
	while (str[length] != c && str[length])
		length++;
	return (length);
}

static int	ft_copy_strs(char const *s, char c, char **split_result, int size)
{
	int		index;
	int		size_str;
	char	*aux;

	index = 0;
	while (index < size)
	{
		while (*s == c)
			s++;
		size_str = ft_size_str(s, c);
		split_result[index] = (char *) malloc(sizeof(char) * (size_str + 1));
		if (split_result[index] == 0)
			return (0);
		aux = split_result[index];
		while (*s != c && *s)
			*aux++ = *s++;
		*aux = '\0';
		index++;
	}
	split_result[index] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		size;
	char	**split_result;

	if (s == 0)
		return (0);
	size = ft_count_strs(s, c);
	split_result = (char **) malloc(sizeof(void *) * (size + 1));
	if (split_result == 0)
		return (0);
	if (ft_copy_strs(s, c, split_result, size) == 0)
	{
		ft_free(split_result);
		return (0);
	}
	return (split_result);
}

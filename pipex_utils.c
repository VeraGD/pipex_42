/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:03:45 by veragarc          #+#    #+#             */
/*   Updated: 2024/10/25 10:03:48 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*r1;
	char	*r2;

	i = 0;
	r1 = (char *)s1;
	r2 = (char *)s2;
	while (r1[i] == r2[i] && (r1[i] != '\0' && r2[i] != '\0') && i < n - 1)
		i++;
	if (n == 0)
		return (0);
	else
		return ((unsigned char)r1[i] - (unsigned char)r2[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	if (res == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		res[i] = s2[j];
		j++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

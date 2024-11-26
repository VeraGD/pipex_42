/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:58:34 by veragarc          #+#    #+#             */
/*   Updated: 2024/11/26 15:59:28 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_one_line(int fd)
{
	char	c;
	char	*str;
	char	*temp;
	char	*aux;

	str = malloc(1 * sizeof(char));
	str[0] = 0;
	while (read(fd, &c, 1) > 0)
	{
		aux = str;
		temp = malloc(2 * sizeof(char));
		temp[0] = c;
		temp[1] = 0;
		str = ft_strjoin(aux, temp);
		free(temp);
		free(aux);
		if (c == '\n')
			break ;
	}
	return (str);
}

void	create_file(t_pipex *struct_pipex)
{
	char	*line;
	char	*limiter;

	limiter = ft_strjoin(struct_pipex->lim, "\n");
	struct_pipex->fd_ini = open("tmp.txt", O_CREAT | O_TRUNC | O_RDWR, 0777);
	while (true)
	{
		line = get_one_line(0);
		if (ft_strncmp(limiter, line, ft_strlen(limiter)) == 0)
		{
			free(limiter);
			break ;
		}
		ft_putstr_fd(line, struct_pipex->fd_ini);
		free(line);
	}
	free(line);
}

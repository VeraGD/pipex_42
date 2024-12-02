/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:50:40 by veragarc          #+#    #+#             */
/*   Updated: 2024/11/28 10:14:44 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_pipex_paths(t_pipex *struct_pipex, int total)
{
	int	i;

	i = 0;
	if (struct_pipex->paths[i] == NULL)
	{
		while (i < total)
		{
			if (struct_pipex->paths[i])
				free(struct_pipex->paths[i]);
			i++;
		}
		free(struct_pipex->paths);
		struct_pipex->paths = NULL;
		free(struct_pipex->cmds);
		struct_pipex->cmds = NULL;
	}
}

void	free_struct(t_pipex *struct_pipex)
{
	if (struct_pipex)
	{
		if (struct_pipex->cmd1_path != NULL)
			free(struct_pipex->cmd1_path);
		if (struct_pipex->cmd1_options != NULL)
			free_split(struct_pipex->cmd1_options);
		if (struct_pipex->cmd2_path != NULL)
			free(struct_pipex->cmd2_path);
		if (struct_pipex->cmd2_options != NULL)
			free_split(struct_pipex->cmd2_options);
		if (struct_pipex->cmds != NULL)
			free(struct_pipex->cmds);
		if (struct_pipex->paths != NULL)
			free_split(struct_pipex->paths);
		if (struct_pipex->pids != NULL)
			free(struct_pipex->pids);
		free(struct_pipex);
	}
}

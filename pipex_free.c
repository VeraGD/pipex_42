/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:50:40 by veragarc          #+#    #+#             */
/*   Updated: 2024/10/25 12:15:59 by veragarc         ###   ########.fr       */
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
		free(struct_pipex);
	}
}

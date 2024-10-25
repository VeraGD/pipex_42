/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:50:40 by veragarc          #+#    #+#             */
/*   Updated: 2024/10/25 09:52:19 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
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
		free(struct_pipex->cmd1_path);
		free_split(struct_pipex->cmd1_options);
		free(struct_pipex->cmd2_path);
		free_split(struct_pipex->cmd2_options);
		free(struct_pipex);
	}
}

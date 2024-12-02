/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:53:58 by veragarc          #+#    #+#             */
/*   Updated: 2024/11/28 15:59:10 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

static char	*env_path(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

char	*aux_path(char **split1, char **split2, char *join, char *join_cmd)
{
	free_split(split1);
	free_split(split2);
	free(join);
	return (join_cmd);
}

char	*get_cmd_path(char *cmd1, char **envp)
{
	char	**split1;
	char	**split2;
	char	*join;
	char	*join_cmd;
	int		i;

	split1 = ft_split(env_path(envp), ':');
	split2 = ft_split(cmd1, ' ');
	i = 0;
	while (i < ft_len_double(split1))
	{
		join = ft_strjoin(split1[i], "/");
		join_cmd = ft_strjoin(join, split2[0]);
		if (access(join_cmd, F_OK) == 0)
		{
			return (aux_path(split1, split2, join, join_cmd));
		}
		free(join_cmd);
		free(join);
		i++;
	}
	ft_printf("Invalid command entered, %s\n", cmd1);
	free_split(split1);
	free_split(split2);
	return (NULL);
}

void	ini_s(t_pipex *struct_pipex, char *cmd1, char *cmd2, char **envp)
{
	char	*cmd1_path;
	char	*cmd2_path;

	cmd1_path = get_cmd_path(cmd1, envp);
	if (cmd1_path != NULL)
	{
		struct_pipex->cmd1_path = cmd1_path;
		struct_pipex->cmd1_options = ft_split(cmd1, ' ');
	}
	cmd2_path = get_cmd_path(cmd2, envp);
	if (cmd2_path != NULL)
	{
		struct_pipex->cmd2_path = cmd2_path;
		struct_pipex->cmd2_options = ft_split(cmd2, ' ');
	}
	struct_pipex->here_doc = 0;
	struct_pipex->lim = NULL;
	struct_pipex->fd_ini = -1;
}

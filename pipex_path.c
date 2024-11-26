/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:53:58 by veragarc          #+#    #+#             */
/*   Updated: 2024/10/25 10:02:47 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path(char *path, int len, char *cmd1)
{
	int		i;
	int		j;
	char	*path_cmd;
	char	*cmd_f;
	char	**split;

	i = 1;
	path_cmd = (char *)malloc((len + 1) * sizeof(char));
	path_cmd[0] = '/';
	while (path[i - 1] != '\0')
	{
		path_cmd[i] = path[i - 1];
		i++;
	}
	path_cmd[i++] = '/';
	j = 0;
	split = ft_split(cmd1, ' ');
	cmd_f = split[0];
	while (cmd_f[j] != '\0')
		path_cmd[i++] = cmd_f[j++];
	path_cmd[i] = '\0';
	free_split(split);
	return (path_cmd);
}

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

static char	*get_env_path(char **envp)
{
	char	*cmd_points_split;
	char	**split1;
	char	**split2;
	char	*cmd_path_slash;
	int		i;

	i = 0;
	split1 = ft_split(env_path(envp), ':');
	cmd_points_split = split1[0];
	split2 = ft_split(cmd_points_split, '/');
	cmd_path_slash = split2[2];
	free_split(split1);
	while (i < 2)
	{
		free(split2[i]);
		i++;
	}
	free(split2);
	return (cmd_path_slash);
}

char	*get_cmd_path(char *cmd1, char **envp)
{
	char	**split3;
	char	*cmd_space_slash;
	char	*path;
	int		len;
	char	*cmd_path_slash;

	cmd_path_slash = get_env_path(envp);
	split3 = ft_split(cmd_path_slash, ' ');
	cmd_space_slash = split3[0];
	len = ft_strlen(cmd_path_slash) + ft_strlen(cmd1) + 2;
	path = get_path(cmd_path_slash, len, cmd1);
	free_split(split3);
	free(cmd_path_slash);
	if (access(path, F_OK) == 0)
		return (path);
	else
	{
		ft_printf("Invalid command entered, %s\n", cmd1);
		free(path);
		return (NULL);
	}
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

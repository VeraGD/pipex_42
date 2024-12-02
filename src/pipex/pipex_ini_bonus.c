/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_ini_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:01:03 by veragarc          #+#    #+#             */
/*   Updated: 2024/11/28 10:16:35 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

static void	check_here(t_pipex *struct_pipex, char **argv)
{
	if (ft_strncmp("here_doc", argv[1], ft_strlen("here_doc")) == 0)
		struct_pipex->here_doc = 1;
	else
		struct_pipex->here_doc = 0;
}

static void	ini_here(t_pipex *struct_pipex, char **argv, char **envp)
{
	int	*pid;
	int	i;

	i = 0;
	struct_pipex->paths = (char **)malloc((3) * sizeof(char *));
	struct_pipex->cmds = (char **)malloc((2) * sizeof(char *));
	pid = (int *)malloc((2) * sizeof(int));
	struct_pipex->lim = argv[2];
	while (i < 2)
	{
		struct_pipex->paths[i] = get_cmd_path(argv[3 + i], envp);
		struct_pipex->cmds[i] = argv[3 + i];
		if (struct_pipex->paths[i] == NULL)
		{
			free_pipex_paths(struct_pipex, i);
			free(pid);
			return ;
		}
		i++;
	}
	struct_pipex->paths[i] = NULL;
	struct_pipex->pids = pid;
	struct_pipex->fd_ini = 0;
}

static void	init_non_doc(t_pipex *s, int argc, char **argv, char **envp)
{
	int	*pid;
	int	i;

	s->paths = (char **)malloc((argc - 2) * sizeof(char *));
	s->cmds = (char **)malloc((argc - 3) * sizeof(char *));
	pid = (int *)malloc((argc - 3) * sizeof(int));
	i = 0;
	while (i < argc - 3)
	{
		s->paths[i] = get_cmd_path(argv[2 + i], envp);
		s->cmds[i] = argv[2 + i];
		if (s->paths[i] == NULL)
		{
			free_pipex_paths(s, i);
			free(pid);
			return ;
		}
		i++;
	}
	s->paths[i] = NULL;
	s->pids = pid;
	s->fd_ini = -1;
}

static void	ini_bonus(t_pipex *struct_pipex, int argc, char **argv, char **envp)
{
	check_here(struct_pipex, argv);
	if (struct_pipex->here_doc == 0)
		init_non_doc(struct_pipex, argc, argv, envp);
	else
		ini_here(struct_pipex, argv, envp);
}

t_pipex	*initialization_bonus(int argc, char **argv, char **envp)
{
	t_pipex	*struct_pipex;

	struct_pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (struct_pipex)
	{
		struct_pipex->cmds = NULL;
		struct_pipex->paths = NULL;
		struct_pipex->pids = NULL;
		struct_pipex->lim = NULL;
		struct_pipex->cmd1_options = NULL;
		struct_pipex->cmd1_path = NULL;
		struct_pipex->cmd2_options = NULL;
		struct_pipex->cmd2_path = NULL;
	}
	if (!struct_pipex)
	{
		ft_printf("Error allocating memory to structure\n");
		free_struct(struct_pipex);
		return (NULL);
	}
	else
	{
		ini_bonus(struct_pipex, argc, argv, envp);
		return (struct_pipex);
	}
}

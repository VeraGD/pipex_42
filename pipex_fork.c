/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:33:58 by veragarc          #+#    #+#             */
/*   Updated: 2024/10/25 12:19:06 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_pipex	*initialization(char *cmd1, char *cmd2, char **envp)
{
	t_pipex	*struct_pipex;

	struct_pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (struct_pipex)
	{
		struct_pipex->cmd1_path = NULL;
		struct_pipex->cmd1_options = NULL;
		struct_pipex->cmd2_path = NULL;
		struct_pipex->cmd2_options = NULL;
		struct_pipex->cmds = NULL;
		struct_pipex->paths = NULL;
		struct_pipex->pids = NULL;
	}
	if (!struct_pipex)
	{
		ft_printf("Error allocating memory to structure\n");
		free_struct(struct_pipex);
		return (NULL);
	}
	else
	{
		ini_s(struct_pipex, cmd1, cmd2, envp);
		return (struct_pipex);
	}
}

static void	first_fork(t_pipex *struct_pipex, char *infile, int pid)
{
	int		infile_fd;

	if (pid == -1)
	{
		ft_printf("Error in fork");
		free_struct(struct_pipex);
		return ;
	}
	if (pid == 0)
	{
		infile_fd = open(infile, O_RDONLY);
		if (infile_fd == -1)
		{
			ft_printf("Error opening infile");
			free_struct(struct_pipex);
			return ;
		}
		dup2(struct_pipex->fd[WRITE_END], 1);
		close(struct_pipex->fd[READ_END]);
		dup2(infile_fd, 0);
		close(infile_fd);
		execve(struct_pipex->cmd1_path, struct_pipex->cmd1_options, NULL);
		ft_printf("Error running execve");
	}
}

static void	second_fork(t_pipex *struct_pipex, char *outfile, int pid)
{
	int		outfile_fd;

	if (pid == -1)
	{
		ft_printf("Error in fork");
		free_struct(struct_pipex);
		return ;
	}
	if (pid == 0)
	{
		outfile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile_fd == -1)
		{
			ft_printf("Error opening and/or creating outfile");
			free_struct(struct_pipex);
			return ;
		}
		dup2(struct_pipex->fd[READ_END], 0);
		close(struct_pipex->fd[WRITE_END]);
		dup2(outfile_fd, 1);
		close(outfile_fd);
		execve(struct_pipex->cmd2_path, struct_pipex->cmd2_options, NULL);
		ft_printf("Error running execve");
	}
}

static void	waiting(int pid1, int pid2)
{
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int	setup_pipe(char **argv, char **envp, char *inf, char *out)
{
	t_pipex	*r;
	int		pid2;
	int		pid1;

	r = initialization(argv[2], argv[3], envp);
	if (r->cmd1_path == NULL || r->cmd2_path == NULL || r == NULL)
	{
		free_struct(r);
		return (1);
	}
	if (pipe(r->fd) == -1)
	{
		ft_printf("Error creating pipe");
		free_struct(r);
		return (1);
	}
	pid1 = fork();
	first_fork(r, inf, pid1);
	pid2 = fork();
	second_fork(r, out, pid2);
	close(r->fd[READ_END]);
	close(r->fd[WRITE_END]);
	waiting(pid1, pid2);
	free_struct(r);
	return (0);
}

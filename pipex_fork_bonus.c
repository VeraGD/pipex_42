/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_fork_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:14:53 by veragarc          #+#    #+#             */
/*   Updated: 2024/11/26 16:17:36 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_fork_b(t_pipex *s, int infile)
{
	if (infile == -1)
	{
		ft_printf("Error opening infile");
		free_struct(s);
		exit(1);
	}
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(s->fd[1], STDOUT_FILENO);
	close(s->fd[0]);
	close(s->fd[1]);
	s->cmd1_options = ft_split(s->cmds[0], ' ');
	execve(s->paths[0], s->cmd1_options, NULL);
	ft_printf("Error running execve");
	free_struct(s);
	exit(1);
}

void	middle_fork(t_pipex *s, int fd_prev, int i)
{
	dup2(fd_prev, STDIN_FILENO);
	close(fd_prev);
	dup2(s->fd[1], STDOUT_FILENO);
	close(s->fd[0]);
	close(s->fd[1]);
	s->cmd1_options = ft_split(s->cmds[i], ' ');
	execve(s->paths[i], s->cmd1_options, NULL);
	ft_printf("Error running execve");
	exit(1);
}

void	last_fork(t_pipex *s, int outfile, int fd_prev, int i)
{
	if (outfile == -1)
	{
		ft_printf("Error opening outfile");
		free_struct(s);
		exit(1);
	}
	dup2(fd_prev, STDIN_FILENO);
	close(fd_prev);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	s->cmd1_options = ft_split(s->cmds[i], ' ');
	execve(s->paths[i], s->cmd1_options, NULL);
	ft_printf("Error running execve");
	exit(1);
}

static void	aux_pipe(t_pipex *r, int argc, char *out)
{
	int	infile_fd;
	int	outfile_fd;

	create_file(r);
	infile_fd = open("tmp.txt", O_RDONLY);
	outfile_fd = open(out, O_WRONLY | O_CREAT | O_APPEND, 0644);
	choose_fork(r, argc - 1, infile_fd, outfile_fd);
	close(r->fd_ini);
	unlink("tmp.txt");
	free_struct(r);
	exit(0);
}

int	setup_pipe_bonus(char **argv, char **envp, char *inf, char *out)
{
	t_pipex	*r;
	int		infile_fd;
	int		outfile_fd;
	int		argc;

	argc = ft_len_double(argv);
	r = initialization_bonus(argc, argv, envp);
	if (r->cmds == NULL || r->paths == NULL || r->pids == NULL || r == NULL)
	{
		free_struct(r);
		return (1);
	}
	if (r->here_doc == 0)
	{
		infile_fd = open(inf, O_RDONLY);
		outfile_fd = open(out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		choose_fork(r, argc, infile_fd, outfile_fd);
		free_struct(r);
	}
	else
		aux_pipe(r, argc, out);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_choose_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:10:15 by veragarc          #+#    #+#             */
/*   Updated: 2024/11/26 16:14:04 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

static int	choose_aux_wait(t_pipex *s, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 3)
		waitpid(s->pids[i++], NULL, 0);
	return (0);
}

static int	choose_aux_close(t_pipex *s, int fd_prev)
{
	if (fd_prev != -1)
		close(fd_prev);
	close(s->fd[1]);
	fd_prev = s->fd[0];
	return (fd_prev);
}

int	choose_fork(t_pipex *s, int argc, int infile, int outfile)
{
	int	i;
	int	fd_prev;

	i = 0;
	fd_prev = -1;
	while (i < argc - 3)
	{
		if (i != argc - 4 && pipe(s->fd) == -1)
			return (ft_printf("Error creating pipe"), free_struct(s), 1);
		s->pids[i] = fork();
		if (s->pids[i] == -1)
			return (ft_printf("Error in fork"), free_struct(s), 1);
		if (s->pids[i] == 0)
		{
			if (i == 0)
				first_fork_b(s, infile);
			else if (i == argc - 4)
				last_fork(s, outfile, fd_prev, i);
			else
				middle_fork(s, fd_prev, i);
		}
		fd_prev = choose_aux_close(s, fd_prev);
		i++;
	}
	return (choose_aux_wait(s, argc));
}

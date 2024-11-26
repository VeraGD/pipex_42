/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pipex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:44:31 by veragarc          #+#    #+#             */
/*   Updated: 2024/11/26 15:57:02 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	aux_main(char **argv, char **envp, char *inf, char *out)
{
	int	argc;

	argc = ft_len_double(argv);
	if (setup_pipe_bonus(argv, envp, inf, out) == 1)
		return (-1);
	else
		return (0);
}

static int	check_here(char *inf)
{
	if (ft_strncmp("here_doc", inf, ft_strlen("here_doc")) == 0)
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*inf;
	char	*out;
	int		u;

	inf = 0;
	out = 0;
	if (argc > 3)
	{
		inf = argv[1];
		out = argv[argc - 1];
		u = check_here(inf);
		if (u == 0 && access(inf, R_OK | W_OK) == 0)
			return (aux_main(argv, envp, inf, out));
		else if (u == 1)
			return (aux_main(argv, envp, inf, out));
		else
			ft_printf("Enter a valid initial file, %s is not valid", argv[1]);
	}
	else
		ft_printf("Invalid number of arguments");
	return (0);
}

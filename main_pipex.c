/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:32:27 by veragarc          #+#    #+#             */
/*   Updated: 2024/10/25 12:14:43 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	aux_main(char **argv, char **envp, char *inf, char *out)
{
	if (setup_pipe(argv, envp, inf, out) == 1)
	{
		free(inf);
		free(out);
		return (-1);
	}
	else
	{
		free(inf);
		free(out);
		return (0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	*inf;
	char	*out;

	inf = 0;
	out = 0;
	if (argc == 5)
	{
		inf = ft_strjoin(argv[1], ".txt");
		out = ft_strjoin(argv[4], ".txt");
		if (access(inf, R_OK | W_OK) == 0)
			return (aux_main(argv, envp, inf, out));
		else
		{
			free(inf);
			free(out);
			ft_printf("Enter a valid initial file, %s is not valid", argv[1]);
		}
	}
	else
		ft_printf("Invalid number of arguments");
	return (0);
}

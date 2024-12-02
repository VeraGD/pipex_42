/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:32:27 by veragarc          #+#    #+#             */
/*   Updated: 2024/11/26 16:18:51 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

static int	aux_main(char **argv, char **envp, char *inf, char *out)
{
	if (setup_pipe(argv, envp, inf, out) == 1)
		return (-1);
	else
		return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*inf;
	char	*out;

	inf = 0;
	out = 0;
	if (argc == 5)
	{
		inf = argv[1];
		out = argv[4];
		if (access(inf, R_OK | W_OK) == 0)
			return (aux_main(argv, envp, inf, out));
		else
			ft_printf("Enter a valid initial file, %s is not valid", argv[1]);
	}
	else
		ft_printf("Invalid number of arguments");
	return (0);
}

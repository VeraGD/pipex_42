/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:32:27 by veragarc          #+#    #+#             */
/*   Updated: 2024/10/25 09:33:20 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		{
			if (setup_pipe(argv, envp, inf, out) == 1)
				return (-1);
		}
		else
			ft_printf("Enter a valid initial file, %s is not valid", argv[1]);
	}
	else
		ft_printf("Invalid number of arguments");
	return (0);
}

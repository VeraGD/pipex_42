/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:04:17 by veragarc          #+#    #+#             */
/*   Updated: 2024/10/25 10:07:43 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdarg.h>
# include <stddef.h>

# ifndef READ_END
#  define READ_END 0
# endif

# ifndef WRITE_END
#  define WRITE_END 1
# endif

typedef struct s_pipex
{
	int		fd[2];
	char	*cmd1_path;
	char	**cmd1_options;
	char	*cmd2_path;
	char	**cmd2_options;
}	t_pipex;

char	**ft_split(char const *s, char c);

int		ft_strlen(const char *str);

int		ft_printf(char const *format, ...);

void	ini_s(t_pipex *struct_pipex, char *cmd1, char *cmd2, char **envp);

int		setup_pipe(char **argv, char **envp, char *inf, char *out);

void	free_struct(t_pipex *struct_pipex);

void	free_split(char **split);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strjoin(char const *s1, char const *s2);

//printf

int		ft_putchar(char c, int cont);

int		ft_putstr(char *str, int cont);

int		ft_putnbr(int nb, int cont);

int		ft_putnbr_u(unsigned int nb, int cont);

int		ft_putnbr_hexa(unsigned int nb, int cont, char d);

int		ft_putptr_hexa(unsigned long nb, int cont);

int		ft_printf(char const *format, ...);

int		ft_printf_bonus(char const *format, ...);

#endif

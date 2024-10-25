/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:47:57 by veragarc          #+#    #+#             */
/*   Updated: 2024/10/25 09:26:18 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_putchar(char c, int cont)
{
	cont = cont + 1;
	write(1, &c, 1);
	return (cont);
}

int	ft_putstr(char *str, int cont)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		str = "(null)";
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	cont = cont + i;
	return (cont);
}

int	ft_putnbr(int nb, int cont)
{
	if (nb == -2147483648)
		cont = ft_putstr("-2147483648", cont);
	else if (nb < 0)
	{
		write(1, "-", 1);
		cont = cont + 1;
		nb = nb * -1;
		cont = ft_putnbr(nb, cont);
	}
	else if (nb > 9)
	{
		cont = ft_putnbr(nb / 10, cont);
		cont = ft_putnbr(nb % 10, cont);
	}
	else if (nb <= 9)
		cont = ft_putchar(nb + '0', cont);
	return (cont);
}

int	ft_putnbr_u(unsigned int nb, int cont)
{
	if (nb > 9)
	{
		cont = ft_putnbr(nb / 10, cont);
		cont = ft_putnbr(nb % 10, cont);
	}
	else if (nb <= 9)
		cont = ft_putchar(nb + '0', cont);
	return (cont);
}

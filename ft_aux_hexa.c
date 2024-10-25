/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:30:58 by veragarc          #+#    #+#             */
/*   Updated: 2024/10/25 09:25:17 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_putnbr_hexa(unsigned int nb, int cont, char d)
{
	char	*base;

	base = 0;
	if (d == 'x')
		base = "0123456789abcdef";
	else if (d == 'X')
		base = "0123456789ABCDEF";
	if (nb >= 16)
		cont = ft_putnbr_hexa(nb / 16, cont, d);
	cont = ft_putchar(base[nb % 16], cont);
	return (cont);
}

int	ft_putptr_hexa(unsigned long nb, int cont)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb == 0)
	{
		write(1, "(nil)", 5);
		cont = cont + 5;
		return (cont);
	}
	if (nb >= 16)
		cont = ft_putptr_hexa(nb / 16, cont);
	cont = ft_putchar(base[nb % 16], cont);
	return (cont);
}

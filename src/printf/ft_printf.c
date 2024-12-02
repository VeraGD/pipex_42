/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:47:15 by veragarc          #+#    #+#             */
/*   Updated: 2024/10/25 09:26:50 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

static int	conversion(char d, va_list args, int cont)
{
	unsigned long	num;

	num = 0;
	if (d == 'c')
		cont = ft_putchar((char)va_arg(args, int), cont);
	else if (d == 's')
		cont = ft_putstr(va_arg(args, char *), cont);
	else if (d == 'd' || d == 'i')
		cont = ft_putnbr(va_arg(args, int), cont);
	else if (d == '%')
		cont = ft_putchar('%', cont);
	else if (d == 'u')
		cont = ft_putnbr_u(va_arg(args, unsigned int), cont);
	else if (d == 'x')
		cont = ft_putnbr_hexa(va_arg(args, unsigned int), cont, d);
	else if (d == 'X')
		cont = ft_putnbr_hexa(va_arg(args, unsigned int), cont, d);
	else if (d == 'p')
	{
		num = va_arg(args, unsigned long);
		if (num > 0)
			cont = ft_putstr("0x", cont);
		cont = ft_putptr_hexa(num, cont);
	}
	return (cont);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		cont;
	int		i;

	va_start(args, format);
	i = 0;
	cont = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			i++;
			cont++;
		}
		else
		{
			i++;
			cont = conversion(format[i], args, cont);
			i++;
		}
	}
	return (cont);
}

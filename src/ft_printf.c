/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:33:48 by kevisout          #+#    #+#             */
/*   Updated: 2024/11/06 13:47:42 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
convert va rediriger l'argument ft_printf (cspdiuXx%) vers la bonne fonction
pour avoir le bon comportement.
*/
int	convert(const char c, va_list arg)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
		count += ft_putptr(va_arg(arg, unsigned long));
	else if (c == 'd')
		count += ft_putnbr(va_arg(arg, int));
	else if (c == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		count += ft_putnbr(va_arg(arg, unsigned int));
	else if (c == 'x')
		count += ft_puthex(va_arg(arg, unsigned int), 'x');
	else if (c == 'X')
		count += ft_puthex(va_arg(arg, unsigned int), 'X');
	else if (c == '%')
		count += ft_putchar(c);
	return (count);
}

/*
ft_printf nous introduit la notion d'arguments variadiques.
Les '...' en argument de ft_printf, indiquent qu'il peut y avoir un nombre
d'argument inconnu a l'avance, c'est le cas pour printf.

va_list est une structure assez complexe et il nous est pas demandee d'y
toucher, on peut la manipuler a l'aide de va_start, end, arg.. et ca suffit.

va_start permet d'initialiser cette structure, la rendant utilisable pour
la suite de notre programme.


*/
int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	arg;

	i = 0;
	count = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
			count += convert(str[i++ + 1], arg);
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (count);
}

/*
#include <stdio.h>
int main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("REAL PRINTF :%s", av[1]);
		ft_printf("MY   PRINTF :%s", av[1]);
		write(1, "\n", 1);
	}
	return (0);
}
*/

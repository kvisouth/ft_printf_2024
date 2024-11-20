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

/* ft_printf retourne le nombre de caractere qu'il a ecrit au total */
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

/* av[1] = ce qu'on veut print av[2] type */
/*
#include <stdio.h>

int main(int ac, char **av)
{
	if (ac == 3)
	{
		int ret1 = 0;
		int	ret2 = 0;
		if (av[2][0] == 'c')
		{
			ret1 = printf("REAL PRINTF : %c\n", av[1][0]);
			ret2 = ft_printf("MY   PRINTF : %c\n", av[1][0]);
		}
		else if(av[2][0] == 's')
		{
			ret1 = printf("REAL PRINTF : %s\n", av[1]);
			ret2 = ft_printf("MY   PRINTF : %s\n", av[1]);
		}
		else if(av[2][0] == 'p')
		{
			ret1 = printf("REAL PRINTF : %p\n", av[1]);
			ret2 = ft_printf("MY   PRINTF : %p\n", av[1]);
		}
		else if(av[2][0] == 'd')
		{
			ret1 = printf("REAL PRINTF : %d\n", atoi(av[1]));
			ret2 = ft_printf("MY   PRINTF : %d\n", atoi(av[1]));
		}
		else if(av[2][0] == 'i')
		{
			ret1 = printf("REAL PRINTF : %i\n", atoi(av[1]));
			ret2 = ft_printf("MY   PRINTF : %i\n", atoi(av[1]));
		}
		else if(av[2][0] == 'u')
		{
			ret1 = printf("REAL PRINTF : %u\n", atoi(av[1]));
			ret2 = ft_printf("MY   PRINTF : %u\n", atoi(av[1]));
		}
		else if(av[2][0] == 'x')
		{
			ret1 = printf("REAL PRINTF : %x\n", atoi(av[1]));
			ret2 = ft_printf("MY   PRINTF : %x\n", atoi(av[1]));
		}
		else if(av[2][0] == 'X')
		{
			ret1 = printf("REAL PRINTF : %X\n", atoi(av[1]));
			ret2 = ft_printf("MY   PRINTF : %X\n", atoi(av[1]));
		}
		else if(av[2][0] == '%')
		{
			ret1 = printf("REAL PRINTF : %%\n");
			ret2 = ft_printf("MY   PRINTF : %%\n");
		}
		printf("\n RETURN VALUE OF printf : %d", ret1);
		printf("\n RETURN VALUE OF ft_printf : %d", ret2);
	}
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevisout <kevisout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:13:24 by kevisout          #+#    #+#             */
/*   Updated: 2024/11/05 15:46:25 by kevisout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
A la difference des putchar, putstr.. de base, ceux-ci retournent un entier
qui est le nombre de caracteres qu'ils ont ecrit car printf retourne le
nombre total de caracteres ecrits.
*/

/*
ft_putchar sera utilisee dans les autres fonctions et pour '%c' et '%%'
Pour ecrire une lettre (c)
*/
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/*
ft_putstr sera utilisee pour '%s'
Pour ecrire une chaine de caractere (str)
*/
int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			write(1, &str[i++], 1);
		return (i);
	}
	return (ft_putstr("(null)"));
}

/*
ft_putnbr sera utilisee pour '%d' '%i' et '%u'
Pour ecrire un nombre en base 10.
*/
int	ft_putnbr(long int nb)
{
	int	cpt;

	cpt = 0;
	if (nb < 0)
	{
		cpt += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		cpt += ft_putnbr(nb / 10);
		cpt += ft_putnbr(nb % 10);
	}
	else
		cpt += ft_putchar(nb + 48);
	return (cpt);
}

/*
ft_puthex sera utilisee pour '%p' '%x' et '%X'
Pour ecrire un nombre en base 16.
*/
int	ft_puthex(unsigned long nb, char x)
{
	int	cpt;

	cpt = 0;
	if (nb >= 16)
	{
		cpt += ft_puthex(nb / 16, x);
		cpt += ft_puthex(nb % 16, x);
	}
	else
	{
		if (nb < 10)
			cpt += ft_putnbr(nb);
		else
			cpt += ft_putchar(nb - 10 + 'a' + (x - 'x'));
	}
	return (cpt);
}

/*
ft_putptr sera utililsee pour '%p'
Pour ecrire une adresse memoire qui est juste 0x suivi de ptr en hexa.
*/
int	ft_putptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_puthex(ptr, 'x');
	return (count);
}

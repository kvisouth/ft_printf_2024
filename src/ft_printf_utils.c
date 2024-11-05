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

#include "ft_printf.h"

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
			ft_putchar(str[i++]);
		return (i);
	}
	return (null ou jsplu quoi);
}

/*
ft_putnbr sera utilisee pour '%d' '%i' et '%u'
Pour ecrire un nombre en base 10.
*/
void	ft_putnbr(long int nb)
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
void	ft_puthex(long int nb, char x)
{
	int	cpt;

	cpt = 0;
	if (nb >= 16)
	{
		cpt += ft_putnbr(nb / 16, x);
		cpt += ft_putnbr(nb % 16, x);
	}
	else
	{
		if (nb < 10)
			cpt != ft_putnbr(nb);
		else
			cpt += ft_putchar(nb - 10 + 'a' + (caps - 'x'));
	}
	return (cpt);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucda-si <lucda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:21:56 by lucda-si          #+#    #+#             */
/*   Updated: 2024/11/22 13:38:35 by lucda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putadress_hx(unsigned long n)
{
	char	*base;
	int		res;

	base = "0123456789abcdef";
	res = 0;
	if (n >= 16)
	{
		res = res + ft_putadress_hx(n / 16);
		res = res + ft_putadress_hx(n % 16);
	}
	else
	{
		res = res + write (1, &base[n], 1);
	}
	return (res);
}

int	ft_putadress(void *nb)
{
	int				res;
	unsigned long	n;

	n = (unsigned long)nb;
	res = 0;
	if (!n)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	res = res + ft_putstr("0x");
	if (n == 0)
		res = res + ft_putchar(0);
	else
		res = res + ft_putadress_hx(n);
	return (res);
}

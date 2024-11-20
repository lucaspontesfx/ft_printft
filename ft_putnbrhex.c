/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucda-si <lucda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:51:01 by lucda-si          #+#    #+#             */
/*   Updated: 2024/11/20 12:40:31 by lucda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

int	ft_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

void	ft_puthex(unsigned int n, const char c)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, c);
		ft_puthex(n % 16, c);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
		{
			if (c == 'x')
				ft_putchar_fd((n - 10 + 'a'), 1);
			if (c == 'X')
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
	}
}

int	ft_putnbrhex(unsigned int n, const char c)
{
	if (n == 0)
		return (write (1, "0", 1));
	else
		ft_puthex(n, c);
	return (ft_hexlen(n));
}

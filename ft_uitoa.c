/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucda-si <lucda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:53:37 by lucda-si          #+#    #+#             */
/*   Updated: 2024/11/20 11:44:45 by lucda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_size(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		i++;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_uitoa(unsigned int n)
{
	char	*str;
	size_t	size;
	int		res;

	res = 0;
	size = get_size(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	str[size] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		size--;
		str[size] = (n % 10) + 48;
		n = n / 10;
	}
	res = ft_putstr(str);
	free (str);
	return (res);
}

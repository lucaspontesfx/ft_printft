/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucda-si <lucda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:21:07 by lucda-si          #+#    #+#             */
/*   Updated: 2024/11/15 12:05:15 by lucda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if ((unsigned char)c == '\0')
	{
		return ((char *)(s + i));
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main (void)
{
	char	str[] = "abcLucasabc";
	char	c = 'L';
	char	*res;

	res = ft_strchr(str, c);

	printf("%s", res);
	return (0);
}
int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (ac == 3)
	{
		printf("%s", ft_strchr(&av[1][j], av[2][j]));
		return (0);
	}
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (unsigned char)c)
		{
			return (ptr);
		}
		ptr++;
	}
	if (c == 0)
	{
		return (ptr);
	}
	return (NULL);
}
*/

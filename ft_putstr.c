<<<<<<< HEAD

#include "ft_printf.h"

int   ft_putstr(const char *str)
{
    int i;

    if(!str)
    {
        return (write(1, "(null)", 6));
    }
    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucda-si <lucda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:42:06 by lucda-si          #+#    #+#             */
/*   Updated: 2024/11/20 11:13:41 by lucda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
	{
		return (ft_putstr("(null)"));
	}
	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}
>>>>>>> 81ff29b (Almos Finished, needing some adjustments)

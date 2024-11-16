/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaspontes <lucaspontes@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:02:33 by lucda-si          #+#    #+#             */
/*   Updated: 2024/11/16 16:11:45 by lucaspontes      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nbr;
	int	i;

	nbr = n;
	if(n < 0)
	{
		n = -n;
		i++;
	}
	if(n >= 10)
	{
		i = ft_putnbr(n / 10);
	}
	else
		i = i + ft_putchar( n % 10 + '0');
	return (i);
}

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

int	ft_putadress(void *ptr)
{
	unsigned long	adress;
	int	count;

	if (!ptr)
	{
		return (write(1, "(null)", 6));
	}
	ft_putstr("0x");
	adress = (unsigned long)ptr;
	count = ft_put_nbr_base(adress, "0123456789abcdef", count, 16);/*TODO*/
}

static	int	check_format(const char *str, int index, va_list args)
{
	if (str[index] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (str[index] == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (str[index] == 'd' || str[index] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (str[index] == 'p')
		return (ft_putadress(va_arg(args, void *)));
	else if(str[index] == 'u')
		return(ft_uitoa(va_arg(args, unsigned int)));/*TODO*/
	else if (str[index] == 'x' || str[index] == 'X')
		return (ft_putnbrhex(va_arg(args, int), str[index]));/*TODO*/
	else if (str[index] == '%')
		return (ft_putpercent());/*Todo*/
	return (0);
	
}

int	ft_printf(char const *str, ...)
{
	va_list	args;/*Store the arguments list*/

	int	i;
	int	res;

	i = 0;
	res = 0;
	if(!str || *str == '\0')
		return (0);
	va_start(args, str);/*initialize the arg list to be read*/
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (!ft_strchr("cspdiuxX%", str[i]))/*ToDo  include my libft to be used*/
			{
				i++;
			}
			res = res + check_format(str, i, args);/*To finalize function*/
		}
		else
			res = res + ft_putchar(str[i]);/*Todo the function*/
		i++;
	}
	va_end(args);/*finalize the list use freeing the resources used*/
	return (res);
}
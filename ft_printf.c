/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucda-si <lucda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:02:33 by lucda-si          #+#    #+#             */
/*   Updated: 2024/11/15 12:05:25 by lucda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	check_format(const char *str, int index, va_list args)
{
	if (str[index] == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (str[index] == 's')
		return (ft_put_char(va_arg(args, char *)));
	else if (str[index] == 'd' || str[index] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if ()
	
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
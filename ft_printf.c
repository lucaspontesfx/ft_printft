/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaspontes <lucaspontes@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:02:33 by lucda-si          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/11/16 16:11:45 by lucaspontes      ###   ########.fr       */
=======
/*   Updated: 2024/11/20 13:11:54 by lucda-si         ###   ########.fr       */
>>>>>>> 81ff29b (Almos Finished, needing some adjustments)
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

<<<<<<< HEAD
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

=======
static int	ft_putnbr(int nbr)
{
	long	n;
	int		i;

	n = nbr;
	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		i++;
	}
	if (n > 9)
	{
		i = ft_putnbr(n / 10);
	}
	i = i + ft_putchar(n % 10 + '0');
	return (i);
}

>>>>>>> 81ff29b (Almos Finished, needing some adjustments)
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
<<<<<<< HEAD
	else if(str[index] == 'u')
		return(ft_uitoa(va_arg(args, unsigned int)));/*TODO*/
	else if (str[index] == 'x' || str[index] == 'X')
		return (ft_putnbrhex(va_arg(args, int), str[index]));/*TODO*/
=======
	else if (str[index] == 'u')
		return (ft_uitoa(va_arg(args, unsigned int)));
	else if (str[index] == 'x' || str[index] == 'X')
		return (ft_putnbrhex(va_arg(args, int), str[index]));
>>>>>>> 81ff29b (Almos Finished, needing some adjustments)
	else if (str[index] == '%')
		return (ft_putpercent());
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		res;
	va_list	args;

	i = 0;
	res = 0;
	if (!str || *str == '\0')
		return (0);
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (!ft_strchr("cspdiuxX%", str[i]))
				i++;
			res = res + check_format(str, i, args);
		}
		else
			res = res + ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (res);
}
/*
#include <stdio.h>
#include "ft_uitoa.c"
#include "ft_putchar.c"
#include "ft_putstr.c"
#include "ft_putpercent.c"
#include "ft_putnbrhex.c"
#include "ft_putadress.c"
#include "ft_strchr.c"

int	main(void)
{
	int	i = 20;
	char c = '%';
	char	name[] = "Brigdes%";
	int a = 42;
    int *ptr = &a;

	ft_printf("The int i is: %d\n", i);
	ft_printf("The c  is: %c\n", c);
	ft_printf("The int name is: %s\n", name);

	// Test with lowercase hexadecimal
	//Hexadecimal (lowercase): ff
    ft_printf("Hexadecimal (lowercase): %x\n", 255);

    // Test with uppercase hexadecimal
	//Hexadecimal (uppercase): FF
    ft_printf("Hexadecimal (uppercase): %X\n", 255);
    // Test with pointers
    ft_printf("Pointer address: %p\n", ptr); // Expected output: Pointer address
	
	return (0);
}
*/

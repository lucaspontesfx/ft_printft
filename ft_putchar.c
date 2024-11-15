/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucda-si <lucda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:45:33 by lucda-si          #+#    #+#             */
/*   Updated: 2024/11/15 12:49:01 by lucda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)/*find out why I should return a int stead of a char*/
{
	write (1, &c, 1);
	return (1);/*why return 1*/
}
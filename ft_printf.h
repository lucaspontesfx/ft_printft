/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucaspontes <lucaspontes@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:58:53 by lucda-si          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/11/15 15:47:36 by lucaspontes      ###   ########.fr       */
=======
/*   Updated: 2024/11/20 12:47:06 by lucda-si         ###   ########.fr       */
>>>>>>> 81ff29b (Almos Finished, needing some adjustments)
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_putnbrhex(unsigned int n, const char c);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putadress(void *nb);
int		ft_uitoa(unsigned int n);
int		ft_putpercent(void);
char	*ft_strchr(const char *s, int c);
<<<<<<< HEAD
void	ft_putstr(char *str);
=======
>>>>>>> 81ff29b (Almos Finished, needing some adjustments)

#endif
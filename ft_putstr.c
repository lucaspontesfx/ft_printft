
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
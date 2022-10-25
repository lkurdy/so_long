/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkurdy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:09:08 by lkurdy            #+#    #+#             */
/*   Updated: 2022/06/16 15:42:58 by lkurdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_upnbrbase(unsigned int n)
{
	int		i;
	char	*up;

	i = 0;
	up = "0123456789ABCDEF";
	i = i + ft_putbase(n, up);
	return (i);
}

int	ft_lownbrbase(unsigned int n)
{
	int		i;
	char	*low;

	low = "0123456789abcdef";
	i = 0;
	i = i + ft_putbase(n, low);
	return (i);
}

void	check(const char c, va_list arg, int *y)
{
	if (c == 'c')
		*y = *y + ft_putchar(va_arg(arg, int));
	else if (c == 's')
		*y = *y + ft_putstr(va_arg(arg, char *));
	else if (c == 'p')
		*y = *y + ft_hex(va_arg(arg, unsigned long long));
	else if (c == 'd' || c == 'i')
		*y = *y + ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		*y = *y + ft_putuns(va_arg(arg, unsigned int));
	else if (c == 'x')
		*y = *y + ft_lownbrbase(va_arg(arg, unsigned int));
	else if (c == 'X')
		*y = *y + ft_upnbrbase(va_arg(arg, unsigned int));
	else if (c == '%')
		*y = *y + write(1, "%", 1);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		y;
	va_list	arg;

	i = 0;
	y = 0;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			check(s[i], arg, &y);
		}
		else
			y = y + write (1, &s[i], 1);
		i++;
	}
	va_end(arg);
	return (y);
}
/*
int main ()
{
	ft_printf("%x %X", 54, 3);
	return 0;
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkurdy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:07:02 by lkurdy            #+#    #+#             */
/*   Updated: 2022/06/16 15:44:08 by lkurdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_putchar(int c)
{
	int	i;

	i = 0;
	i = i + write(1, &c, 1);
	return (i);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
		i = i + write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			i = i + write(1, "-", 1);
			nb = -nb;
		}
		i = i + ft_putbase((unsigned int)nb, "0123456789");
	}
	return (i);
}

int	ft_putuns(unsigned int n)
{
	int	i;

	i = 0;
	i = i + ft_putbase(n, "0123456789");
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		i = i + write(1, "(null)", 6);
		return (i);
	}
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

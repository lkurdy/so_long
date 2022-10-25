/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkurdy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:00:01 by lkurdy            #+#    #+#             */
/*   Updated: 2022/06/16 15:43:16 by lkurdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	hexlength(unsigned long long nb, unsigned long long d)
{
	int	i;

	i = 1;
	while (nb > d)
	{
		nb = nb / d;
		i++;
	}
	return (i);
}

char	*hexfill(char *s, unsigned long long nb, unsigned long long l)
{
	int	i;

	i = 0;
	while (nb >= l)
	{
		s[i] = nb % l + 48;
		i++;
		nb = nb / l;
	}
	s[i++] = nb + 48;
	s[i] = '\0';
	return (s);
}

int	ft_puthex(unsigned long long n, char *base)
{
	int					i;
	char				*s;
	int					j;
	int					p;
	unsigned long long	l;

	l = 0;
	while (base[l])
		l++;
	i = 0;
	j = 0;
	p = 0;
	s = malloc(sizeof(char) * hexlength(n, l) + 2);
	if (!s)
		return (0);
	s = hexfill(s, n, l);
	while (s[j + 1])
		j++;
	while (j >= 0)
	{
		p = s[j--] - 48;
		i = i + write(1, &base[p], 1);
	}
	return (free(s), i);
}

int	lowhex(unsigned long long n)
{
	int		i;
	char	*low;

	low = "0123456789abcdef";
	i = 0;
	i = i + ft_puthex(n, low);
	return (i);
}

int	ft_hex(unsigned long long n)
{
	int	i;

	i = 0;
	if (!n)
	{
		i = i + write(1, "(nil)", 5);
		return (i);
	}
	i = i + write(1, "0x", 2);
	i = i + lowhex(n);
	return (i);
}

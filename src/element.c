/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkurdy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:54:11 by lkurdy            #+#    #+#             */
/*   Updated: 2022/07/17 21:54:56 by lkurdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	el(char b, int y)
{
	if (b == 'P')
		return (y + 1);
	return (y);
}

int	element2(int i, char *buf, t_data *img)
{
	int	y;

	y = 0;
	while (buf[i] && buf[i] != 'E')
		i++;
	if (!buf[i])
		return (free(buf), 0);
	i = 0;
	while (buf[i] && (buf[i] == '1' || buf[i] == '0'
			|| buf[i] == 'C' || buf[i] == 'E'
			|| buf[i] == 'P' || buf[i] == '\n'))
	{
		i++;
		y = el(buf[i], y);
	}
	if (buf[i] || y > 1)
		return (free(buf), 0);
	img->str = malloc(sizeof(char) * i + 1);
	i = 0;
	while (buf[i])
	{
		img->str[i] = buf[i];
		i++;
	}
	return (img->str[i] = '\0', free(buf), 1);
}

void	coins(int i, char *buf, t_data *img)
{
	while (buf[i++])
	{
		if (buf[i] == 'C')
			img->graille++;
	}
}

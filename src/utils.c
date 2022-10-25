/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkurdy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:25:59 by lkurdy            #+#    #+#             */
/*   Updated: 2022/06/16 15:28:37 by lkurdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	up(t_data *img)
{
	int	i;

	i = 0;
	while (img->str[i] != 'P')
		i++;
	if (img->str[i - (img->length + 1)] == '1')
		return ;
	if (img->str[i - (img->length + 1)] == 'C')
		img->graille--;
	if (img->str[i - (img->length + 1)] == 'E')
	{
		if (img->graille == 0)
			ft_close(img);
		else
			return ;
	}
	img->str[i] = '0';
	img->str[i - (img->length + 1)] = 'P';
	img->side = 3;
	img->c++;
	put_map(img);
}

void	down(t_data *img)
{
	int	i;

	i = 0;
	while (img->str[i] != 'P')
		i++;
	if (img->str[i + (img->length + 1)] == '1')
		return ;
	if (img->str[i + (img->length + 1)] == 'C')
		img->graille--;
	if (img->str[i + (img->length + 1)] == 'E')
	{
		if (img->graille == 0)
			ft_close(img);
		else
			return ;
	}
	img->str[i] = '0';
	img->str[i + (img->length + 1)] = 'P';
	img->side = 2;
	img->c++;
	put_map(img);
}

void	left(t_data *img)
{
	int	i;

	i = 0;
	while (img->str[i] != 'P')
		i++;
	if (img->str[i - 1] == '1')
		return ;
	if (img->str[i - 1] == 'C')
		img->graille--;
	if (img->str[i - 1] == 'E')
	{
		if (img->graille == 0)
			ft_close(img);
		else
			return ;
	}
	img->str[i] = '0';
	img->str[i - 1] = 'P';
	img->side = 4;
	img->c++;
	put_map(img);
}

void	right(t_data *img)
{
	int	i;

	i = 0;
	while (img->str[i] != 'P')
		i++;
	if (img->str[i + 1] == '1')
		return ;
	if (img->str[i + 1] == 'C')
		img->graille--;
	if (img->str[i + 1] == 'E')
	{
		if (img->graille == 0)
			ft_close(img);
		else
			return ;
	}
	img->str[i] = '0';
	img->str[i + 1] = 'P';
	img->side = 1;
	img->c++;
	put_map(img);
}

int	key(int keycode, t_data *img)
{
	if (keycode == 65307)
		ft_close(img);
	else if (keycode == 'W' || keycode == 'w')
		up(img);
	else if (keycode == 'A' || keycode == 'a')
		left(img);
	else if (keycode == 'S' || keycode == 's')
		down(img);
	else if (keycode == 'D' || keycode == 'd')
		right(img);
	return (0);
}

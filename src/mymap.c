/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkurdy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:24:25 by lkurdy            #+#    #+#             */
/*   Updated: 2022/06/29 14:04:11 by lkurdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_close(t_data *img)
{
	mlx_destroy_image(img->mlx, img->wall);
	mlx_destroy_image(img->mlx, img->lman);
	mlx_destroy_image(img->mlx, img->rman);
	mlx_destroy_image(img->mlx, img->uman);
	mlx_destroy_image(img->mlx, img->dman);
	mlx_destroy_image(img->mlx, img->end);
	mlx_destroy_image(img->mlx, img->bouffe);
	mlx_destroy_image(img->mlx, img->empty);
	mlx_destroy_window(img->mlx, img->win);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	free(img->str);
	exit (0);
}

void	map(t_data *img)
{
	img->wall = mlx_xpm_file_to_image
		(img->mlx, "img/wall.xpm", &img->x, &img->y);
	img->lman = mlx_xpm_file_to_image
		(img->mlx, "img/lman.xpm", &img->x, &img->y);
	img->rman = mlx_xpm_file_to_image
		(img->mlx, "img/rman.xpm", &img->x, &img->y);
	img->bouffe = mlx_xpm_file_to_image
		(img->mlx, "img/bouffe.xpm", &img->x, &img->y);
	img->end = mlx_xpm_file_to_image
		(img->mlx, "img/end.xpm", &img->x, &img->y);
	img->dman = mlx_xpm_file_to_image
		(img->mlx, "img/dman.xpm", &img->x, &img->y);
	img->uman = mlx_xpm_file_to_image
		(img->mlx, "img/uman.xpm", &img->x, &img->y);
	img->empty = mlx_xpm_file_to_image
		(img->mlx, "img/empty.xpm", &img->x, &img->y);
}

void	put_remp(t_data *img, int x, int y, int i)
{
	if (img->str[i] == 'P')
	{
		if (img->side == 1)
			mlx_put_image_to_window(img->mlx,
				img->win, img->rman, x * 64, y * 64);
		if (img->side == 2)
			mlx_put_image_to_window(img->mlx,
				img->win, img->dman, x * 64, y * 64);
		if (img->side == 3)
			mlx_put_image_to_window(img->mlx,
				img->win, img->uman, x * 64, y * 64);
		if (img->side == 4)
			mlx_put_image_to_window(img->mlx,
				img->win, img->lman, x * 64, y * 64);
	}
	if (img->str[i] == '0')
		mlx_put_image_to_window(img->mlx,
			img->win, img->empty, x * 64, y * 64);
	if (img->str[i] == 'E' && img->graille == 0)
		mlx_put_image_to_window(img->mlx,
			img->win, img->end, x * 64, y * 64);
}

static void	remplace(int *x, int *y, int *i)
{
	*x = 0;
	*y = 0;
	*i = 0;
}

void	put_map(t_data *img)
{
	int	x;
	int	y;
	int	i;

	if (img->c == 0)
		map(img);
	remplace(&x, &y, &i);
	ft_printf("%d\n", img->c);
	while (img->str[i])
	{
		if (img->str[i] == 'C')
			mlx_put_image_to_window(img->mlx, img->win,
				img->bouffe, x * 64 + 24, y * 64 + 32);
		if (img->str[i] == '1')
			mlx_put_image_to_window(img->mlx,
				img->win, img->wall, x * 64, y * 64);
		put_remp(img, x, y, i);
		x++;
		if (img->str[i] == '\n')
		{
			y++;
			x = 0;
		}
		i++;
	}
}

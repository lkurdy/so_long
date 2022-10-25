/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkurdy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:54:47 by lkurdy            #+#    #+#             */
/*   Updated: 2022/07/17 21:46:08 by lkurdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	remp(char *line, int fd)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int	check2(int fd, char *line, int i, t_data *img)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (line)
	{
		free(line);
		k++;
		line = get_next_line(fd);
		if (!line && j == -1)
			return (img->height = k, j);
		else if (!line)
			return (0);
		j = 0;
		if (ft_strlen(line) != i + 1 || line[0] != '1'
			|| line[i - 1] != '1')
			return (remp(line, fd));
		while (line[j] == '1')
			j++;
		if (j == i)
			j = -1;
	}
	return (0);
}

int	check_list(char *v, t_data *img)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(v, O_RDONLY);
	if (fd == -1)
		return (0);
	line = get_next_line(fd);
	i = 0;
	while (line[i] == '1')
		i++;
	img->length = i;
	if (i != ft_strlen(line) - 1)
		return (0);
	i = check2(fd, line, i, img);
	if (i == -1)
		return (close(fd), 1);
	return (close(fd), 0);
}

int	element(char *v, t_data *img)
{
	int		fd;
	int		rd;
	int		i;
	char	*buf;

	buf = malloc(sizeof(char) * ((img->length + 1) * img->height + 1));
	fd = open(v, O_RDONLY);
	if (fd == -1)
		return (free(buf), 0);
	rd = read(fd, buf, (img->length + 1) * img->height);
	close(fd);
	buf[rd] = '\0';
	if (rd == -1)
		return (free(buf), 0);
	i = 0;
	while (buf[i] && buf[i] != 'P')
		i++;
	if (!buf[i])
		return (free(buf), 0);
	i = 0;
	coins(i, buf, img);
	return (element2(i, buf, img));
}

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc != 2)
		return (ft_printf("Error\nInvalid Number of Arguments\n"));
	if (!check_list(argv[1], &img))
		return (ft_printf("Error\nInvalid Map\n"));
	img.graille = 0;
	img.side = 1;
	img.c = 0;
	if (!element(argv[1], &img))
		return (ft_printf("Error\nMissing or multiple objects in map\n"));
	if (img.graille == 0)
		return (ft_printf("Error\nMissing item\n"));
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx,
			img.length * 64, img.height * 64, "PacMan");
	put_map(&img);
	mlx_hook(img.win, 17, 0, ft_close, &img);
	mlx_key_hook(img.win, key, &img);
	mlx_loop(img.mlx);
	return (0);
}

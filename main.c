#include "get_next_line.h"

int	check2(int fd, char *line, int i)
{
	int	j;

	while (line)
	{
		j = 0;
		free(line);
		line = get_next_line(fd);
		if (i != -1 && (ft_strlen(line) != i + 1 || line[0] != '1'
				|| line[i - 1] != '1'))
		{
			while (line)
			{
				free(line);
				line = get_next_line(fd);
			}
			return (0);
		}
		while (i != -1 && line[j] == '1')
			j++;
		if (j == i)
			i = -1;
	}
	return (i);
}

int	check(int a, char *v)
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
	if (i != ft_strlen(line) - 1)
		return (0);
	i = check2(fd, line, i);
	if (i == -1)
		return (close(fd), 1);
	return (close(fd), 0);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;

	if (argc != 2)
		return (printf("Error\n"));
	if (!check(argc, argv[1]))
		return (printf("Error\n"));
	
	return (0);
}

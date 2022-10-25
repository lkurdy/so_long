/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkurdy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 18:49:33 by lkurdy            #+#    #+#             */
/*   Updated: 2022/06/29 15:53:48 by lkurdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../mlx_linux/mlx.h"
# include <stdarg.h>

typedef struct s_data
{
	void	*img;
	void	*mlx;
	char	*addr;
	int		bits;
	int		line;
	int		endian;
	int		length;
	int		height;
	void	*bouffe;
	int		graille;
	void	*lman;
	void	*end;
	void	*rman;
	void	*dman;
	void	*uman;
	void	*empty;
	void	*wall;
	void	*win;
	char	*str;
	int		side;
	int		x;
	int		y;
	int		c;
}				t_data;
int		ft_strcmp(char *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_strlen(char *s);
char	*get_next_line(int fd);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	put_map(t_data *img);
int		key(int keycode, t_data *img);
int		ft_close(t_data *img);
void	image(t_data *img);
int		length(unsigned int nb, unsigned int d);
char	*fill(char *s, unsigned int nb, unsigned int l);
int		ft_putbase(unsigned int n, char *base);
int		ft_putchar(int c);
int		ft_putuns(unsigned int n);
int		ft_putstr(char *s);
int		ft_upnbrbase(unsigned int n);
int		ft_lownbrbase(unsigned int n);
void	check(const char c, va_list arg, int *y);
int		ft_printf(const char *s, ...);
int		hexlength(unsigned long long nb, unsigned long long d);
char	*hexfill(char *s, unsigned long long nb, unsigned long long l);
int		ft_puthex(unsigned long long n, char *base);
int		lowhex(unsigned long long n);
int		ft_hex(unsigned long long n);
int		ft_putnbr(int nb);
int		element2(int i, char *buf, t_data *img);
void	coins(int i, char *buf, t_data *img);

#endif

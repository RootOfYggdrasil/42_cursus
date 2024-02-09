/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:40:19 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/04/01 16:22:16 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define M_WIDTH 1200
# define M_HEIGHT 800
# define _USE_MATH_DEFINES

# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "key_linux.h"

typedef struct s_coord
{
	float	x;
	float	y;
	float	x1;
	float	y1;
	int		clr;
	int		z;
	int		z1;
}				t_coord;

typedef struct s_point
{
	int	z;
	int	clr;
}				t_point;

typedef struct s_map
{
	int		projection;
	int		max_width;
	int		max_height;
	int		width;
	int		height;
	int		zoom;
	int		shift_x;
	int		shift_y;
	int		shift_z;
	float	angle;
	float	alpha;
	t_point	**p_a;
}				t_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	void	*mlx_win;
	void	*mlx;
	t_map	*map;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	ft_read_file(int fd, t_map *map);

void	ft_error(char *s);
int		ft_close(t_data *meta);
void	ft_create_image(t_map *map);

int		key_hook(int key_code, t_data *meta);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	ft_bresenham(t_coord c, t_data *data);
void	test_draw(t_data *s_data);

void	ft_apply_zoom(t_coord *c, t_data *data);
void	ft_apply_shift(t_coord *c, t_data *data);
void	ft_apply_shiftz(t_coord *c, t_data *data);

void	ft_image(t_data	*data);

void	ft_data_elaboration(t_coord *c, t_data *data);
#endif
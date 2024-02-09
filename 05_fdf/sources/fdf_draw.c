/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:18:15 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/04/01 16:26:01 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	ft_fmax(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	ft_fabs(float a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

void	my_mlx_pixel_put(t_data *d, int x, int y, int color)
{
	char	*dst;

	if (x >= M_WIDTH || x <= 0 || y >= M_HEIGHT || y <= 0)
		return ;
	dst = d->addr + (y * d->line_length + x * (d->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_bresenham(t_coord c, t_data *data)
{
	float	x_step;
	float	y_step;
	float	max;

	ft_data_elaboration(&c, data);
	x_step = c.x1 - c.x;
	y_step = c.y1 - c.y;
	max = ft_fmax(ft_fabs(x_step), ft_fabs(y_step));
	if (max != 0)
	{
		x_step /= max;
		y_step /= max;
	}
	while ((int)(c.x - c.x1) || (int)(c.y - c.y1))
	{
		if (c.clr)
			my_mlx_pixel_put(data, c.x, c.y, c.clr);
		else if (c.z || c.z1)
			my_mlx_pixel_put(data, c.x, c.y, 0xe80c00);
		else
			my_mlx_pixel_put(data, c.x, c.y, 0xFFFFFF);
		c.x += x_step;
		c.y += y_step;
	}
}

void	test_draw(t_data *img)
{
	t_coord	c;

	c.y = 0;
	while (c.y < img->map->height)
	{
		c.x = 0;
		while (c.x < img->map->width)
		{
			if (c.x < img->map->width - 1)
			{
				c.x1 = c.x + 1;
				c.y1 = c.y;
				ft_bresenham(c, img);
			}
			if (c.y < img->map->height - 1)
			{
				c.x1 = c.x;
				c.y1 = c.y + 1;
				ft_bresenham(c, img);
			}
			c.x++;
		}
		c.y++;
	}
}

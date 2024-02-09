/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:36:51 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/04/01 15:30:08 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_iso_rotation(float *x, float *y, float angle)
{
	int	tmp;

	tmp = *x;
	*x = (*x * cos(angle)) - (*y * sin(angle));
	*y = (tmp * sin(angle)) + (*y * cos(angle));
}

void	ft_isometric(float *x, float *y, float angle, int z)
{
	int	tmp;

	tmp = *x;
	*x = (*x - *y) * cos(angle);
	*y = (tmp + *y) * sin(angle) - z;
}

void	ft_apply_zoom(t_coord *c, t_data *data)
{
	c->x *= data->map->zoom;
	c->y *= data->map->zoom;
	c->x1 *= data->map->zoom;
	c->y1 *= data->map->zoom;
}

void	ft_apply_shift(t_coord *c, t_data *data)
{
	c->x += data->map->shift_x;
	c->y += data->map->shift_y;
	c->x1 += data->map->shift_x;
	c->y1 += data->map->shift_y;
}

void	ft_data_elaboration(t_coord *c, t_data *data)
{
	c->clr = data->map->p_a[(int)c->y][(int)c->x].clr;
	if (!c->clr && data->map->p_a[(int)c->y1][(int)c->x1].clr)
		c->clr = data->map->p_a[(int)c->y1][(int)c->x1].clr;
	c->z = data->map->p_a[(int)c->y][(int)c->x].z * data->map->shift_z;
	c->z1 = data->map->p_a[(int)c->y1][(int)c->x1].z * data->map->shift_z;
	ft_apply_zoom(c, data);
	if (data->map->projection == 1)
	{
		ft_isometric(&c->x, &c->y, data->map->angle, c->z);
		ft_isometric(&c->x1, &c->y1, data->map->angle, c->z1);
	}
	ft_iso_rotation(&c->x, &c->y, data->map->alpha);
	ft_iso_rotation(&c->x1, &c->y1, data->map->alpha);
	ft_apply_shift(c, data);
}

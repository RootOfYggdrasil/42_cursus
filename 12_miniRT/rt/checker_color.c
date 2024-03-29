/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpollini <lpollini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:37:06 by lpollini          #+#    #+#             */
/*   Updated: 2024/03/03 21:38:42 by lpollini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_rt.h"

double	modulus(double a)
{
	if (a > 0)
		return (a - (double)(long long)a);
	return (1 + (a - (double)(long long)a));
}

char	checker_disr_cyl(t_transform tr, t_ray *r, t_vec3_d col)
{
	int			temp;
	t_vec3_d	d;
	char		i;

	i = 1;
	d = r->data.point_normal;
	d = v3d_normalize((t_vec3_d){d.x, 0, d.z});
	temp = (0.5 + atan2(d.z, d.x) / (2 * M_PI)) * 500;
	if (temp % 20 >= 10)
		i = -i;
	if (fabs(v3d_dot(tr.rtn, v3d_sub(r->data.hit_point,
					tr.pos))) > 0.5)
		i = -i;
	if (i == 1)
		r->data.color = v3d_sub((t_vec3_d){255, 255, 255}, col);
	else
		r->data.color = col;
	return (1);
}

char	checker_disr_sphere(t_vec3_d offset, t_ray *r, t_vec3_d col)
{
	t_vec3_d	d;
	t_vec2_i	on_pg;
	char		i;

	i = 1;
	d = r->data.point_normal;
	on_pg.x = (0.5 + atan2(d.z, d.x) / (2 * M_PI)) * 200;
	on_pg.y = (0.5 - asin(d.y) / (M_PI)) * 100;
	on_pg.x += offset.x / 2;
	if (on_pg.x % 20 >= 10)
		i = -i;
	if (on_pg.y % 20 >= 10)
		i = -i;
	if (i == 1)
		r->data.color = v3d_sub((t_vec3_d){255, 255, 255}, col);
	else
		r->data.color = col;
	return (1);
}

int	checker_disr_plane(t_transform tr, t_ray *r, t_vec3_d pt, t_vec3_d col)
{
	t_vec3_d	tempx;
	t_vec3_d	tempy;
	char		i;
	double		lol;

	i = 0;
	if (tr.rtn.y)
		tempx = v3d_normalize((t_vec3_d){0.01,
				-tr.rtn.z / tr.rtn.y, 1});
	else
		tempx = (t_vec3_d){0, 1, 0};
	tempy = v3d_cross(tr.rtn, tempx);
	i = 1;
	pt = v3d_sub(pt, tr.pos);
	lol = tempx.y * tempy.z - tempx.z * tempy.y;
	i = checker_cases(lol, tempx, tempy, pt);
	if (i == 1)
		r->data.color = v3d_sub((t_vec3_d){255, 255, 255}, col);
	else
		r->data.color = col;
	return (1);
}

char	checker_cases(double lol, t_vec3_d tempx, t_vec3_d tempy, t_vec3_d pt)
{
	char	i;

	i = 1;
	if (plian_module(lol) < POSITIVE_LIM)
	{
		lol = pt.x / tempy.x;
		if (modulus(lol) > 0.5)
			i = -i;
		if (tempx.y)
			lol = (pt.y - lol * tempy.y) / tempx.y;
		else
			lol = (pt.z - lol * tempy.z) / tempx.z;
		if (modulus(lol) > 0.5)
			i = -i;
	}
	else
	{
		if (modulus((tempx.y * pt.z - tempx.z * pt.y) / lol) > 0.5)
			i = -i;
		if (modulus((pt.y * tempy.z - pt.z * tempy.y) / lol) > 0.5)
			i = -i;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:51:33 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/04/01 16:26:31 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	key_hookk1(t_data *meta)
{
	meta->map->zoom = 10;
	meta->map->shift_x = 400;
	meta->map->shift_y = 400;
	meta->map->shift_z = 1;
	meta->map->angle = 0.8;
	meta->map->alpha = 0;
	meta->map->projection = 1;
}

int	key_hook1(int key_code, t_data *meta)
{
	if (key_code == KEY_5)
		meta->map->alpha += 0.05;
	if (key_code == KEY_6)
		meta->map->alpha -= 0.05;
	if (key_code == KEY_1)
	{
		key_hookk1(meta);
	}
	if (key_code == KEY_2)
	{
		meta->map->alpha = 0;
		meta->map->angle = 0;
		meta->map->projection = 0;
	}
	if (key_code == KEY_3)
	{
		meta->map->alpha = 0;
		meta->map->angle = 0;
		meta->map->projection = 1;
	}
	ft_image(meta);
	test_draw(meta);
	return (0);
}

int	key_hook(int key_code, t_data *meta)
{
	if (key_code == KEY_ESCAPE)
		ft_close(meta);
	if (key_code == KEY_0)
		putchar('\n');
	if (key_code == KEY_D)
		meta->map->shift_x += 10;
	if (key_code == KEY_A)
		meta->map->shift_x -= 10;
	if (key_code == KEY_W)
		meta->map->shift_y -= 10;
	if (key_code == KEY_S)
		meta->map->shift_y += 10;
	if (key_code == KEY_7)
		meta->map->shift_z += 1;
	if (key_code == KEY_8)
		meta->map->shift_z -= 1;
	if (key_code == KEY_PLUS)
		meta->map->zoom += 1;
	if (key_code == KEY_MINUS)
		meta->map->zoom -= 1;
	if (key_code == KEY_T)
		meta->map->angle += 0.05;
	if (key_code == KEY_Y)
		meta->map->angle -= 0.05;
	return (key_hook1(key_code, meta));
}

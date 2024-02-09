/* ************************************************************************** */
/*						                                                    */
/*						                                :::      ::::::::   */
/*   fdf_image.c                                        :+:      :+:    :+:   */
/*						                            +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>					+#+  +:+	   +#+        */
/*						                        +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:43:10 by sdel-gra		  #+#	#+#			 */
/*   Updated: 2023/03/13 18:15:25 by sdel-gra         ###   ########.fr       */
/*						                                                    */
/* ************************************************************************** */

#include "../includes/fdf.h"
	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
void	ft_image(t_data	*data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	data->img = NULL;
	data->img = mlx_new_image(data->mlx, M_WIDTH, M_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

void	ft_create_image(t_map *map)
{
	t_data	d;

	d.map = map;
	d.mlx = mlx_init();
	d.mlx_win = mlx_new_window(d.mlx, map->max_width, map->max_height, "");
	d.img = mlx_new_image(d.mlx, map->max_width, map->max_height);
	d.addr = mlx_get_data_addr(d.img, &d.bits_per_pixel,
			&d.line_length, &d.endian);
	mlx_put_image_to_window(d.mlx, d.mlx_win, d.img, 0, 0);
	mlx_hook(d.mlx_win, 17, 0L, ft_close, (void *)&d);
	mlx_hook(d.mlx_win, 02, 1L << 0, key_hook, &d);
	mlx_loop(d.mlx);
}

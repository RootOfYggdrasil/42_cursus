/* ************************************************************************** */
/*		                                                                    */
/*		                                                :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*		                                            +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>		            +#+  +:+       +#+        */
/*		                                        +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:09:27 by sdel-gra		  #+#    #+#             */
/*   Updated: 2023/03/13 18:09:49 by sdel-gra         ###   ########.fr       */
/*		                                                                    */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_freepoint(t_point **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

int	ft_close(t_data *meta)
{
	int	y;

	y = 0;
	if (meta->img)
		mlx_destroy_image(meta->mlx, meta->img);
	mlx_destroy_window(meta->mlx, meta->mlx_win);
	mlx_destroy_display(meta->mlx);
	while (y < meta->map->height)
	{
		ft_freepoint((meta->map->p_a) + y);
		y++;
	}
	free(meta->map->p_a);
	free(meta->mlx);
	exit(0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:42:30 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/04/01 16:20:18 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
/*
void	vedolagentescema(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			printf("%d,%d ", map.p_a[i][j].z, map.p_a[i][j].clr);
			j++;
		}
		printf("\n\n");
		i++;
	}	
}*/

int	main(int argc, char const *argv[])
{
	t_map	map;

	if (argc == 2 && argv)
	{
		map = (t_map){0, M_WIDTH, M_HEIGHT, 0, 0, 10, 200, 200, 1, 0, 0, NULL};
		map.shift_y = map.max_height / 2;
		map.shift_x = map.max_width / 2;
		ft_read_file(open(argv[1], O_RDONLY), &map);
		ft_create_image(&map);
	}
	read(0, NULL, 0);
	return (0);
}

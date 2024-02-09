/* ************************************************************************** */
/*					                                                        */
/*					                                    :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*					                                +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>					+#+  +:+       +#+        */
/*					                            +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:42:42 by sdel-gra		  #+#	#+#		     */
/*   Updated: 2023/03/13 18:13:09 by sdel-gra         ###   ########.fr       */
/*					                                                        */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_char_count(char *s, char c)
{
	int	i;
	int	out;

	i = 0;
	out = 0;
	while (s && s[i] == c)
		i++;
	while (s && s[i])
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\n'))
			out++;
		i++;
	}
	return (out);
}

void	ft_create_line(t_map *map, char **str_array, int h)
{
	int		i;
	char	**str_toconvert;
	char	*b;

	str_toconvert = NULL;
	b = "0123456789ABCEDF";
	i = 0;
	map->p_a[h] = (t_point *)ft_calloc(map->width, sizeof(t_point));
	while (str_array && str_array[i])
	{
		if (ft_strchr(str_array[i], ','))
		{
			str_toconvert = ft_split(str_array[i], ',');
			map->p_a[h][i].z = ft_atoi(str_toconvert[0]);
			map->p_a[h][i].clr = ft_atoib(str_toconvert[1] + 2, b, 16);
			str_toconvert[0] = ft_free(str_toconvert + 0);
			str_toconvert[1] = ft_free(str_toconvert + 1);
			free(str_toconvert);
			str_toconvert = NULL;
		}
		else
			map->p_a[h][i].z = ft_atoi(str_array[i]);
		str_array[i] = ft_free(str_array + i);
		i++;
	}
}

void	ft_create_array(t_map *map, t_list *list)
{
	char	**str_array;
	t_list	*next_lst;
	int		h;

	h = 0;
	str_array = NULL;
	map->p_a = ft_calloc(map->height, sizeof(t_point *));
	next_lst = list;
	while (next_lst != NULL && next_lst->content)
	{
		str_array = ft_split(next_lst->content, ' ');
		ft_create_line(map, str_array, h);
		h++;
		next_lst = next_lst->next;
		free(str_array);
		str_array = NULL;
	}
}

void	ft_read_file(int fd, t_map *map)
{
	char	*line;
	t_list	*list;

	list = NULL;
	line = get_next_line(fd);
	map->width = ft_char_count(line, ' ') + 1;
	ft_lstadd_back(&list, ft_lstnew(line));
	while (line)
	{
		map->height++;
		line = get_next_line(fd);
		ft_lstadd_back(&list, ft_lstnew(line));
	}
	line = ft_free(&line);
	ft_create_array(map, list);
	ft_lstclear(&list, free);
}

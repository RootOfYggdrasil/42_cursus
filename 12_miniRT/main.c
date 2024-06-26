/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:08:34 by lpollini          #+#    #+#             */
/*   Updated: 2024/03/15 14:08:27 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/mini_rt.h"

void	ft_img_obj(t_window *w)
{
	t_list			*ptr;
	t_gameobject	*p;

	if (!w->scene)
		return ;
	ptr = w->scene;
	while (ptr)
	{
		p = (t_gameobject *)ptr->content;
		if (p != NULL && p->text != NULL)
		{
			p->texture.img.img = mlx_xpm_file_to_image(w->mlx, p->text,
					&p->texture.size.x, &p->texture.size.y);
			p->texture.img.addr = mlx_get_data_addr(p->texture.img.img,
					&p->texture.img.bps, &p->texture.img.ll,
					&p->texture.img.en);
			if (p->texture.img.img == NULL || p->texture.img.addr == NULL)
				ft_print_error("texture error", w, NULL);
		}
		ptr = ptr->next;
	}
}

void	clean_scene_list(t_list *lst, t_window *win, char mode)
{
	if (!lst)
		return ;
	if (lst && lst->content)
	{
		if (mode && ((t_gameobject *)lst->content)->mtlnss == -1)
		{
			mlx_destroy_image(win->mlx,
				((t_gameobject *)lst->content)->texture.img.img);
			free(((t_gameobject *)lst->content)->text);
		}
		free(lst->content);
	}
	clean_scene_list(lst->next, win, mode);
	free(lst);
}

int	win_close(t_window *win)
{
	if (!win)
		exit(0);
	win->do_exit = 1;
	clean_scene_list(win->scene, win, 1);
	clean_scene_list(win->lights, win, 0);
	mlx_destroy_image(win->mlx, win->skybox.img.img);
	mlx_destroy_image(win->mlx, win->img.img);
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
	free_mat(win->rt);
	printf("called close window.\n");
	exit(0);
	return (0);
}
void	ft_print_window(t_window *w);

int	ft_char_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argn, char *args[])
{
	t_window	w;

	(void)argn;
	ft_memset(&w, 0, sizeof(t_window));
	if (!(argn == 2 || argn == 3))
		ft_print_error(NOARGS, &w, NULL);
	else if (argn == 3 && ft_char_digit(args[2]))
		ft_print_error(NOSIZE, &w, NULL);
	ft_open_rt(&w, args);
	w.mlx = mlx_init();
	if (initw(&w))
		ft_print_error(NOINIT, &w, NULL);
	rft_cast(&w, NULL, 0);
	ft_img_obj(&w);
	my_image_creator(&w);
	mlx_put_image_to_window(w.mlx, w.win, w.img.img, 0, 0);
	mlx_hook(w.win, 17, 1L << 0, win_close, &w);
	mlx_hook(w.win, 2, 1L << 0, manage_keys, &w);
	mlx_mouse_hook(w.win, manage_mouse, &w);
	mlx_loop_hook(w.mlx, loop_rt, &w);
	mlx_loop(w.mlx);
	return (0);
}

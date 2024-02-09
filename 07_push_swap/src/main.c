/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:40:01 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/11/23 15:16:49 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	**list_a;
	t_list	**list_b;

	if (ac < 2)
		stderr_exit("Wrong Number of Arguments");
	ft_check_args(ac, av + 1);
	list_a = (t_list **) malloc(sizeof(t_list));
	list_b = (t_list **) malloc(sizeof(t_list));
	if (!(list_a && list_b))
	{
		ft_free_list(list_b);
		ft_free_list(list_a);
		stderr_exit("Malloc Error");
	}
	*list_a = NULL;
	*list_b = NULL;
	ft_init_list(list_a, ac, av + 1);
	if (!is_sorted(list_a))
		ft_sort(list_a, list_b);
	ft_free_list(list_b);
	ft_free_list(list_a);
	return (0);
}

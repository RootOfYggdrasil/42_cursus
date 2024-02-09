/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:28:29 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/11/23 13:58:06 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_bits(int n_max)
{
	int		mb;

	mb = 0;
	while ((n_max >> mb) != 0)
		mb++;
	return (mb);
}

void	ft_radix_sort(t_list **l_a, t_list **l_b)
{
	int		mb;
	int		size;
	t_list	*list_a;
	int		i;
	int		j;

	i = 0;
	list_a = *l_a;
	size = ft_lstsize(list_a);
	mb = ft_max_bits(size - 1);
	while (i < mb)
	{
		j = 0;
		while (j++ < size)
		{
			list_a = *l_a;
			if (((list_a->i >> i) & 1) == 1)
				ft_rab(l_a, 'a');
			else
				ft_pab(l_a, l_b, 'b');
		}
		while (ft_lstsize(*l_b) != 0)
			ft_pab(l_a, l_b, 'a');
		i++;
	}
}

void	ft_sort_3(t_list **l_a, int min)
{
	if (is_sorted(l_a))
		return ;
	if ((*l_a)->i == min && (*l_a)->next->i != min + 1)
		ft_rab(l_a, 'a');
	if ((*l_a)->i > min + 1)
	{
		if ((*l_a)->next->i == min)
			ft_rab(l_a, 'a');
		else
			ft_sab(l_a, 'a');
	}
	if ((*l_a)->i == min + 1)
	{
		if ((*l_a)->next->i == min)
			ft_sab(l_a, 'a');
		else
			ft_rrab(l_a, 'a');
	}
}

void	ft_sort_middle(t_list **l_a, t_list **l_b, int size)
{
	int	distance;
	int	tmp;

	tmp = size;
	while (size > 3)
	{
		distance = ft_lst_distance(l_a, tmp - size);
		while (distance > 0 && distance < 3)
		{
			ft_rab(l_a, 'a');
			distance--;
		}
		while (distance > 2 && distance < size)
		{
			ft_rrab(l_a, 'a');
			distance++;
		}
		size--;
		if (is_sorted(l_a))
			break ;
		ft_pab(l_a, l_b, 'b');
	}
	ft_sort_3(l_a, tmp - size);
	while (ft_lstsize(*l_b) > 0)
		ft_pab(l_a, l_b, 'a');
}

void	ft_sort(t_list **l_a, t_list **l_b)
{
	int	n;

	n = ft_lstsize(*l_a);
	if (n > 5)
		ft_radix_sort(l_a, l_b);
	else if (n == 2)
		ft_sab(l_a, 'a');
	else if (n == 3)
		ft_sort_3(l_a, 0);
	else
		ft_sort_middle(l_a, l_b, n);
}

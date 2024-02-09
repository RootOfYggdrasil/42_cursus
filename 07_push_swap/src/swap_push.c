/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:39:05 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/11/23 13:48:18 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_list **l)
{
	t_list	*first;
	t_list	*next;
	t_list	tmp;

	if (ft_lstsize(*l) < 2)
		return (-1);
	first = *l;
	next = first->next;
	if (!first && !next)
		stderr_exit("Error occured while swapping!");
	tmp.i = first->i;
	first->i = next->i;
	next->i = tmp.i;
	tmp.value = first->value;
	first->value = next->value;
	next->value = tmp.value;
	return (0);
}

/* a to write "sa" in output, b to write "sb" in output*/
int	ft_sab(t_list **l, char op)
{
	if (ft_swap(l) == -1)
		return (-1);
	if (op == 'a')
		ft_putendl_fd("sa", 1);
	else if (op == 'b')
		ft_putendl_fd("sb", 1);
	return (0);
}

int	ft_push(t_list **l_a, t_list **l_b)
{
	t_list	*h_a;
	t_list	*h_b;
	t_list	*tmp;

	if (ft_lstsize(*l_b) == 0)
		return (-1);
	h_a = *l_a;
	h_b = *l_b;
	tmp = h_b;
	h_b = h_b->next;
	*l_b = h_b;
	if (!h_a)
	{
		h_a = tmp;
		h_a->next = NULL;
		*l_a = h_a;
	}
	else
	{
		tmp->next = h_a;
		*l_a = tmp;
	}
	return (0);
}

/* a to write "pa" in output, b to write "pb" in output*/
int	ft_pab(t_list **l_a, t_list **l_b, char op)
{
	if (op == 'a')
	{
		if (ft_push(l_a, l_b) == -1)
			return (-1);
		ft_putendl_fd("pa", 1);
	}
	else if (op == 'b')
	{
		if (ft_push(l_b, l_a) == -1)
			return (-1);
		ft_putendl_fd("pb", 1);
	}
	return (0);
}

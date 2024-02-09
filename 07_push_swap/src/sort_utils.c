/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:29:04 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/11/23 15:28:06 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **l)
{
	int		out;
	t_list	*elem;

	out = 1;
	elem = *l;
	while (elem && elem->next)
	{
		if (elem->next->value < elem->value)
		{
			out = 0;
			break ;
		}
		elem = elem->next;
	}
	return (out);
}

t_list	*ft_min(t_list **l)
{
	t_list	*head;
	int		min_exist;
	t_list	*min;

	min = NULL;
	min_exist = 0;
	head = *l;
	while (head)
	{
		if ((head->i < 0) && (!min_exist || min->value > head->value))
		{
			min = head;
			min_exist = 1;
		}
		head = head->next;
	}
	return (min);
}

long	ft_atoi_long(const char *nptr)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	num = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		nptr++;
	if (nptr[i] == '-')
		sign = sign * -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		nptr++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = (num * 10) + nptr[i] - '0';
		nptr++;
	}
	return (num * sign);
}

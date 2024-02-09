/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:45:00 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/11/23 15:28:19 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	full free a list
*/
void	ft_free_list(t_list **l)
{
	t_list	*head;
	t_list	*tmp;

	head = *l;
	while (l && head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	if (l)
		free(l);
}

/*
	full free an array of string
*/
void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		free(str[i--]);
	}
	free(str);
}

void	ft_init_list(t_list **l_a, int ac, char **av)
{
	char	**splitted;
	int		i;

	i = 0;
	if (ac == 2)
		splitted = ft_split(av[0], ' ');
	else
		splitted = av;
	while (splitted[i])
		ft_lstadd_back(l_a, ft_lstnew(ft_atoi_long(splitted[i++])));
	if (ac == 2)
		ft_free(splitted);
	ft_assign_index(l_a);
}

/*
	Set index to the all the node of a list
*/
void	ft_assign_index(t_list **l)
{
	int		i;
	t_list	*elem;

	i = 0;
	elem = ft_min(l);
	while (elem)
	{
		elem->i = i++;
		elem = ft_min(l);
	}
}

/*
	Distance from the head to the N number
*/
int	ft_lst_distance(t_list **l, int n)
{
	int		out;
	t_list	*elem;

	elem = *l;
	out = 0;
	while (elem)
	{
		if (elem->i == n)
			return (out);
		elem = elem->next;
		out++;
	}
	return (out);
}

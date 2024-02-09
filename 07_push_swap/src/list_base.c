/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:31:23 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/11/23 15:11:15 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Function from libft updated
*/

/*
	Libft Create New Node adapted for t_list of push_swap
*/
t_list	*ft_lstnew(int value)
{
	t_list	*n;

	n = (t_list *) malloc(sizeof(*n));
	if (!n)
		return (NULL);
	n->next = NULL;
	n->i = -1;
	n->value = value;
	return (n);
}

/*
	Libft Add Back adapted for t_list of push_swap
*/
void	ft_lstadd_back(t_list **l, t_list *new)
{
	t_list	*last;

	if (*l)
	{
		last = ft_lstlast(*l);
		last->next = new;
		new->next = NULL;
	}
	else
	{
		*l = new;
		(*l)->next = NULL;
	}
}

/*
	Libft List Add front adapted for t_list of push_swap
*/
void	ft_lstadd_front(t_list **l, t_list *new_head)
{
	new_head->next = *l;
	*l = new_head;
}

/*
	Libft List last adapted for t_list of push_swap
*/
t_list	*ft_lstlast(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

/*
	Libft List Size adapted for t_list of push_swap
*/
int	ft_lstsize(t_list *lst)
{
	int		out;
	t_list	*next_lst;

	next_lst = lst;
	out = 0;
	while (next_lst != NULL)
	{
		out++;
		next_lst = next_lst->next;
	}
	return (out);
}

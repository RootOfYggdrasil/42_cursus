/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:10:21 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/11/23 15:24:17 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate(t_list **l)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*l) < 2)
		return (-1);
	head = *l;
	tail = ft_lstlast(head);
	*l = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

/* a to write "ra" in output, b to write "rb" in output*/
int	ft_rab(t_list **l_a, char op)
{
	if (ft_rotate(l_a) == -1)
		return (-1);
	if (op == 'a')
		ft_putendl_fd("ra", 1);
	else if (op == 'b')
		ft_putendl_fd("rb", 1);
	return (0);
}

int	ft_reverse_rotate(t_list **l)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*l) < 2)
		return (-1);
	head = *l;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *l;
	*l = tail;
	return (0);
}

/* a to write "rra" in output, b to write "rrb" in output*/
int	ft_rrab(t_list **l_a, char op)
{
	if (ft_reverse_rotate(l_a) == -1)
		return (-1);
	if (op == 'a')
		ft_putendl_fd("rra", 1);
	else if (op == 'b')
		ft_putendl_fd("rrb", 1);
	return (0);
}

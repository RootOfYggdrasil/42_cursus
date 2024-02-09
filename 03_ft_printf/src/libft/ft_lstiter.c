/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:57:12 by sdel-gra          #+#    #+#             */
/*   Updated: 2022/10/05 16:57:14 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*next_lst;

	next_lst = lst;
	if (f)
	{
		while (next_lst != NULL)
		{
			(*f)(next_lst -> content);
			next_lst = next_lst->next;
		}
	}
}

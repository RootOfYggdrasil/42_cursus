/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:57:17 by sdel-gra          #+#    #+#             */
/*   Updated: 2022/10/11 14:57:18 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*next_lst;

	next_lst = lst;
	if (next_lst != NULL)
		while (next_lst->next != NULL)
			next_lst = next_lst->next;
	return (next_lst);
}

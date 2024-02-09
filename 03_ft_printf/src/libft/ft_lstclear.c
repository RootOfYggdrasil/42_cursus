/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:18:38 by sdel-gra          #+#    #+#             */
/*   Updated: 2022/10/11 15:18:47 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (del)
	{
		if (lst != NULL && *lst != NULL)
		{
			ft_lstclear(&(*lst)->next, del);
			ft_lstdelone(*lst, del);
			*lst = NULL;
		}
	}
}

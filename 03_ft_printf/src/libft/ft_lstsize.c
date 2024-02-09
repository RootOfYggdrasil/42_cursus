/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:46:21 by sdel-gra          #+#    #+#             */
/*   Updated: 2022/10/11 14:53:11 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:31:00 by sdel-gra          #+#    #+#             */
/*   Updated: 2022/10/11 17:07:59 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*out;

	out = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			out = (char *)s + i;
		i++;
	}	
	if (s[i] == (char) c)
		out = (char *)s + i;
	return (out);
}

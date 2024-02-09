/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:19:42 by sdel-gra          #+#    #+#             */
/*   Updated: 2022/10/11 18:19:45 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	f(char	*delim_pointer, size_t str_size, char c, char const *s)
{
	delim_pointer = ft_strchr(s, c);
	if (delim_pointer != NULL)
		str_size = delim_pointer - s;
	else
	{
		delim_pointer = ft_strchr(s, '\0');
		str_size = delim_pointer - s;
	}
	return (str_size);
}

char	**f2(char **out, size_t str_count, char const *s, char c)
{
	size_t	str_size;
	size_t	i;

	i = 0;
	while (i < str_count && *s)
	{
		if (*s == c)
			s++;
		else
		{
			str_size = f(NULL, str_size, c, s);
			out[i] = (char *)ft_calloc(sizeof(char), (str_size + 1));
			if (!out[i])
				break ;
			ft_memmove(out[i], s, str_size);
			out[i][str_size] = 0;
			i++;
			s += str_size;
		}
	}
	if (!out[i])
		out[i] = (char *)ft_calloc(1, sizeof(char));
	out[i] = 0;
	return (out);
}

size_t	ft_count_delim(const char *s, int c)
{
	int		i;
	size_t	out;

	out = 1;
	i = 0;
	if (!s || !s[i])
		return (0);
	if (s[i] == c)
		out -= 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			out++;
		i++;
	}
	return (out);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	size_t	str_count;

	str_count = ft_count_delim(s, c);
	out = (char **)malloc(sizeof(char *) * (str_count + 1));
	if (!out)
		return (NULL);
	out = f2(out, str_count, s, c);
	return (out);
}

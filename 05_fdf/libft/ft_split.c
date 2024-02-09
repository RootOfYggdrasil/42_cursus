/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:19:42 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/04/01 16:04:40 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
/*
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
	while (s && i < str_count && *s)
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
}*/

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t		cur;

	cur = 0;
	while (s2[cur] != '\0' && cur < n)
	{
		s1[cur] = s2[cur];
		cur++;
	}
	while (cur < n)
	{
		s1[cur] = '\0';
		cur++;
	}
	return (s1);
}

static	char	*ft_after_split(char const *s, const char c)
{
	while (*s && *(s + 1) == c && *s == c)
		s++;
	if (*s == c)
		s++;
	return ((char *)s);
}

static	void	ft_nsplit(char const *s, const char c, size_t *n)
{
	size_t	i;

	i = 0;
	*n = 1;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			(*n)++;
		i++;
	}
	if (!*s)
		*n = 0;
}

static	char	*ft_allocate(char **s_dest, char *s_sorg,
size_t *len, size_t *p)
{
	int	i;

	i = *p;
	(*p)++;
	s_dest[i] = (char *)malloc((*len + 1) * sizeof(char));
	if (!s_dest[i])
		return (NULL);
	ft_strncpy(s_dest[i], s_sorg - *len, *len);
	s_dest[i][*len] = 0;
	*len = 0;
	return (s_dest[i]);
}

char	**ft_split(char const *s, char c)
{
	size_t	n_of;
	char	**s_split;
	char	*s_sup;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	s_sup = ft_after_split(s, c);
	ft_nsplit(s_sup, c, &n_of);
	s_split = (char **)ft_calloc((n_of + 1), sizeof(char *));
	if (!s_split)
		return (NULL);
	while (*s_sup)
	{
		if (*s_sup != c && *s_sup)
			len++;
		else if (len && *s_sup)
			ft_allocate(s_split, s_sup, &len, &i);
		s_sup++;
	}
	if (*s && *(s_sup - 1) != c)
		s_split[i] = ft_allocate(s_split, s_sup, &len, &i);
	s_split[i] = NULL;
	return (s_split);
}

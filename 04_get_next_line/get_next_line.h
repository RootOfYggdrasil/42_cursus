/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <sdel-gra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:56:14 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/02/14 15:11:34 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);

char	*ft_free(char **ptr);
int		ft_strchr_i(const char *s, char c);
char	*ft_calloc_char(size_t nmemb);
char	*ft_strjoin_free(char *s1, char const *s2);
char	*ft_substr_split(char **s, int len);

#endif

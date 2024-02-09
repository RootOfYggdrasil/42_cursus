/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:51:20 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/03/21 18:51:22 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "libft/libft.h"

//print %c
int	print_perc(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

int	print_putchar(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

// full print the char with flag
int	print_char(t_pf_flags flag, char c, int fd)
{
	int	count;

	count = 1;
	if (flag.width)
	{
		if (flag.isminus)
		{
			ft_putchar_fd(c, fd);
			count += print_space_w(flag.width - 1);
		}
		else
		{
			count += print_space_w(flag.width - 1);
			ft_putchar_fd(c, fd);
		}
	}
	else
		ft_putchar_fd(c, fd);
	return (count);
}

//print (null)
int	print_strnull(t_pf_flags flag, char *s, int fd, int i)
{
	int	count;

	count = 0;
	if (flag.width)
	{
		if (flag.isminus)
		{
			while (s[count] && (!flag.pe || count < (int)flag.precision))
				count += print_putchar(s[count], fd);
			count += print_space_w(flag.width - ft_strlen(s));
		}
		else
		{
			count += print_space_w((int)flag.width - ft_strlen(s));
			while (s[i])
				count += print_putchar(s[i++], fd);
		}
	}
	else
		while (s[count] && (!flag.pe || count < (int)flag.precision))
			ft_putchar_fd(s[count++], fd);
	return (count);
}

// full print string with flag
int	print_str(t_pf_flags flag, char *s, int fd, int i)
{
	int	count;

	count = 0;
	if (s && flag.width)
	{
		if (flag.isminus)
		{
			while (s[count] && (!flag.pe || count < (int)flag.precision))
				count += print_putchar(s[count], fd);
			count += print_space_w(flag.width - ft_strlen(s));
		}
		else
		{
			count += print_space_w((int)flag.width - (int)flag.precision);
			while (s[i] && i < (int) flag.precision)
				count += print_putchar(s[i++], fd);
		}
	}
	else if (s)
		while (s[count] && (!flag.pe || count < (int)flag.precision))
			ft_putchar_fd(s[count++], fd);
	else if (!s && (flag.precision > 5 || !flag.precision))
		count += print_strnull(flag, "(null)", 1, 0);
	return (count);
}

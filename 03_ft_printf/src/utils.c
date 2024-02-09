/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:48:09 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/03/31 16:56:57 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "libft/libft.h"

//print 0 for N times
int	print_0(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	return (i);
}

// print 0x or 0X
int	print_zerox(char conv)
{
	if (conv == 'x')
		return (print_putchar('0', 1) + print_putchar('x', 1));
	else
		return (print_putchar('0', 1) + print_putchar('X', 1));
}

int	print_nbrhex(unsigned int n, const char c, int out)
{
	if (n >= 16)
	{
		out = print_nbrhex(n / 16, c, out);
		n = n % 16;
	}
	if (n <= 9)
		ft_putchar_fd('0' + n, 1);
	else
	{
		if (c == 'X')
		{
			ft_putchar_fd('A' + n - 10, 1);
		}
		if (c == 'x')
		{
			ft_putchar_fd('a' + n - 10, 1);
		}
	}
	return (out + 1);
}

// print and convert unsigned long in Hexadecimal
int	print_int_to_hex(unsigned int n, const char c, int out)
{
	if (n >= 16)
	{
		out = print_int_to_hex(n / 16, c, out);
		n = n % 16;
	}
	if (n <= 9)
		ft_putchar_fd('0' + n, 1);
	else
	{
		if (c == 'X')
		{
			ft_putchar_fd('A' + n - 10, 1);
		}
		if (c == 'x')
		{
			ft_putchar_fd('a' + n - 10, 1);
		}
	}
	return (out + 1);
}

int	print_l_to_hex(unsigned long n, const char c, int out)
{
	if (n >= 16)
	{
		out = print_l_to_hex(n / 16, c, out);
		n = n % 16;
	}
	if (n <= 9)
		ft_putchar_fd('0' + n, 1);
	else
	{
		ft_putchar_fd('a' + n - 10, 1);
	}
	return (out + 1);
}

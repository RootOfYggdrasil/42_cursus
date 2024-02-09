/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:49:14 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/03/21 19:49:16 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "libft/libft.h"

// print the sign if it's needed 
int	print_sign(t_pf_flags flag, int nbr)
{
	if (flag.isplus || nbr < 0)
	{
		if (nbr < 0)
			return (print_putchar('-', 1));
		else
			return (print_putchar('+', 1));
	}
	if (flag.isspace || nbr < 0)
	{
		if (nbr < 0)
			return (print_putchar('-', 1));
		else
			return (print_putchar(' ', 1));
	}
	return (0);
}

// print a number in base 10
int	print_nbr(long int n, int out)
{
	if (n < 0)
		n = -n;
	if (n >= 10)
	{
		out = print_nbr(n / 10, out);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar_fd('0' + n, 1);
	return (out + 1);
}

// count the nbr of digit in a specified base
int	count_nbrdigit(int n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n /= base;
		n = -n;
	}
	while (n > 0)
	{
		i++;
		n /= base;
	}
	return (i);
}

int	print_unsnbr(unsigned int n, int out)
{
	if (n >= 10)
	{
		out = print_unsnbr(n / 10, out);
		n = n % 10;
	}
	if (n <= 9)
		ft_putchar_fd('0' + n, 1);
	return (out + 1);
}

int	count_unsnbrdigit(unsigned long n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n /= base;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:53:33 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/03/31 21:46:14 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "libft/libft.h"

// handle and call the printer function for the number and the sign
int	print_hex_midhandler(t_pf_flags flag, unsigned long nbr, int i)
{
	int	count;

	count = 0;
	if (flag.conv == 'p')
		count += print_zerox('x');
	else if (flag.ishashtag && flag.width > 0)
		count += print_zerox(flag.conv);
	if (flag.precision)
	{
		count += print_0(flag.precision - i);
	}
	if (flag.conv == 'p')
		count += print_l_to_hex(nbr, 'x', 0);
	else
		count += print_nbrhex((unsigned int)nbr, flag.conv, 0);
	return (count);
}

void	reducereduce(t_pf_flags flag, unsigned long nbr, int *count, int i)
{
	if (flag.isminus)
	{
		*count += print_hex_midhandler(flag, nbr, i);
		*count += print_space_w(flag.width - flag.precision);
	}
	else
	{
		if (flag.iszero && !flag.pe)
			*count += print_0(flag.width - flag.precision);
		else
			*count += print_space_w(flag.width - flag.precision);
		*count += print_hex_midhandler(flag, nbr, i);
	}
}

// main function to print Hexadecimal #, width, precision, 0,
int	print_hex(t_pf_flags flag, int nbr, int count, int i)
{
	i = count_unsnbrdigit((unsigned int)nbr, 16);
	if (flag.width)
	{
		if ((size_t)i > flag.precision)
			flag.precision = i;
		if (flag.ishashtag)
			flag.width -= 2;
		reducereduce(flag, nbr, &count, i);
	}
	else
	{
		if ((flag.ishashtag || flag.width > 0) && nbr != 0)
			count += print_zerox(flag.conv);
		if ((int)flag.precision < i)
			count += print_0(0);
		else
			count += print_0((int)flag.precision - i);
		count += print_int_to_hex(nbr, flag.conv, 0);
	}
	return (count);
}

int	print_pointer(t_pf_flags flag, unsigned long nbr, int count, int i)
{
	i = count_unsnbrdigit(nbr, 16);
	if (nbr && flag.width)
	{
		if ((size_t)i > flag.precision)
			flag.precision = i;
		flag.width -= 2;
		reducereduce(flag, nbr, &count, i);
	}
	else if (nbr)
	{
		count += print_zerox('x');
		if ((int)flag.precision < i)
			count += print_0(0);
		else
			count += print_0((int)flag.precision - i);
		count += print_l_to_hex(nbr, flag.conv, 0);
	}
	else
		count += print_str(flag, "(nil)", 1, 0);
	return (count);
}

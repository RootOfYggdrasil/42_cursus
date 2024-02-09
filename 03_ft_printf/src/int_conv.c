/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:41:14 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/02/07 11:41:19 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "libft/libft.h"

void	reduceto25u(t_pf_flags flag, unsigned int nbr, int *count, int i)
{
	if (flag.isminus)
	{
		*count += print_int_unsmidhandler(flag, nbr, i);
		*count += print_space_w(flag.width - flag.precision);
	}
	else
	{
		if (flag.iszero && !flag.pe)
			*count += print_0(flag.width - flag.precision);
		else
			*count += print_space_w(flag.width - flag.precision);
		*count += print_int_unsmidhandler(flag, nbr, i);
	}
}

// main function to print nbr
int	print_int(t_pf_flags flag, int nbr, int i, int count)
{
	i = count_nbrdigit(nbr, 10);
	if (flag.width)
	{
		if (i > (int)flag.precision)
			flag.precision = i;
		if (flag.isplus || flag.isspace || nbr < 0)
			flag.width--;
		reduceto25i(flag, nbr, &count, i);
	}
	else
	{
		count = print_sign(flag, nbr);
		if (flag.precision)
			count += print_0(flag.precision - i);
		count += print_nbr((long int)nbr, 0);
	}
	return (count);
}

// print only nbr and sign if required
int	print_int_midhandler(t_pf_flags flag, int nbr, int i)
{
	int	count;

	count = 0;
	count = print_sign(flag, nbr);
	if (flag.precision)
	{
		count += print_0(flag.precision - i);
	}
	if (flag.iszero && !flag.pe)
		count += print_0(flag.width - flag.precision);
	count += print_nbr((long int)nbr, 0);
	return (count);
}

int	print_int_unsmidhandler(t_pf_flags flag, unsigned int nbr, int i)
{
	int	count;

	count = 0;
	count = print_sign(flag, nbr / 10);
	if (flag.precision)
	{
		count += print_0(flag.precision - i);
	}
	if (nbr == 0 && flag.precision == 0)
		count += print_putchar(' ', 1);
	else
		count += print_unsnbr(nbr, 0);
	return (count);
}

int	print_unsint(t_pf_flags flag, unsigned int nbr, int i, int count)
{
	i = count_unsnbrdigit(nbr, 10);
	if (flag.width)
	{
		if (i > (int)flag.precision && nbr != 0)
			flag.precision = i;
		if (flag.isplus || flag.isspace || (nbr == 0 && flag.pe))
			flag.width--;
		reduceto25u(flag, nbr, &count, i);
	}
	else
	{
		count = print_sign(flag, nbr / 10);
		if (flag.precision)
			count += print_0(flag.precision - i);
		count += print_unsnbr(nbr, 0);
	}
	return (count);
}

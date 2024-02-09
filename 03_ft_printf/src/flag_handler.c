/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:22:32 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/03/31 21:24:40 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "libft/libft.h"

// Set Printf_flag struct to default value
void	flag_initialize(t_pf_flags *flag)
{
	flag->width = 0;
	flag->precision = 0;
	flag->iszero = false;
	flag->isminus = false;
	flag->ishashtag = false;
	flag->isspace = false;
	flag->isplus = false;
	flag->iswidth = false;
	flag->isprecision = false;
	flag->pe = false;
	flag->conv = 0;
}

void	reduceto25i(t_pf_flags flag, int nbr, int *count, int i)
{
	if (flag.isminus)
	{
		*count += print_int_midhandler(flag, nbr, i);
		*count += print_space_w(flag.width - flag.precision);
	}
	else
	{
		if (!flag.iszero)
			*count += print_space_w((int)flag.width - (int)flag.precision);
		*count += print_int_midhandler(flag, nbr, i);
	}
}

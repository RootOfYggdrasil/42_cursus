/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:24:32 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/03/30 14:24:32 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "libft/libft.h"

// print the space need in width
int	print_space_w(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	return (i);
}

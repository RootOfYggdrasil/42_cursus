/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:00:03 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/03/31 21:26:36 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "libft/libft.h"

// s e' in posizione i-esima
int	found_perc(const char *s, va_list args, t_pf_flags flags, int *i)
{
	int	out;

	out = 0;
	out += flag_conv(s, args, &flags, i);
	return (out);
}

// call function to print the variable and the flag return length
int	p_conv(char conv, va_list args, size_t length, t_pf_flags flag)
{
	if (conv == '%')
		length += print_perc();
	if (conv == 'c')
		length += print_char(flag, va_arg(args, int), 1);
	if (conv == 's')
		length += print_str(flag, va_arg(args, char *), 1, 0);
	if (conv == 'x' || conv == 'X')
		length += print_hex(flag, va_arg(args, unsigned int), 0, 0);
	if (conv == 'p')
		length += print_pointer(flag, va_arg(args, unsigned long), 0, 0);
	if (conv == 'd' || conv == 'i')
		length += print_int(flag, va_arg(args, int), 0, 0);
	if (conv == 'u')
		length += print_unsint(flag, va_arg(args, unsigned int), 0, 0);
	return (length);
}

/* a
*/
int	analize_input(const char *s, va_list args, size_t length)
{
	t_pf_flags	flags;
	int			i;

	i = 0;
	flag_initialize(&flags);
	while (s && s[i])
	{
		if (s && s[i] == '%')
		{
			i++;
			length += found_perc(s, args, flags, &i);
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			length++;
			i++;
		}	
	}
	return (length);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		length;

	va_start(args, input);
	length = analize_input(input, args, 0);
	va_end(args);
	return (length);
}

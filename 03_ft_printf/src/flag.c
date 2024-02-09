/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:45:01 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/03/31 17:07:24 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "libft/libft.h"

int	ft_isdigit_not0(int c)
{
	return (c > '0' && c <= '9');
}

// search for conv and set to value
void	search_conv(const char c, t_pf_flags *flag)
{
	char	*tmp;
	int		j;

	j = 0;
	tmp = "cspdiuxX%";
	while (tmp[j])
	{
		if (tmp[j] == c)
		{
			flag->conv = c;
			break ;
		}
		j++;
	}
}

//search for flag and set them to their value
void	search_flag(const char *s, int *i, t_pf_flags *flag)
{
	if (s[*i] == '0')
		flag->iszero = true;
	if (s[*i] == '#')
		flag->ishashtag = true;
	if (s[*i] == '-')
		flag->isminus = true;
	if (s[*i] == '+')
		flag->isplus = true;
	if (s[*i] == ' ')
		flag->isspace = true;
	while (ft_isdigit(s[*i]))
	{
		if (!(flag->pe))
			flag->width = flag->width * 10 + s[*i] - '0';
		else
			flag->precision = flag->precision * 10 + s[*i] - '0';
		(*i)++;
	}
	if (s[*i] == '.')
		flag->pe = true;
}

/*	read stringand search flag or conv until we find a conv
* 
*/
int	flag_conv(const char *s, va_list args, t_pf_flags *flag, int *i)
{
	while (s && s[*i])
	{
		search_flag(s, i, flag);
		if (flag->pe)
			flag->iszero = false;
		search_conv(s[*i], flag);
		(*i)++;
		if (flag->conv)
			break ;
	}
	if (flag->conv)
	{
		return (p_conv(flag->conv, args, 0, *flag));
	}
	return (0);
}

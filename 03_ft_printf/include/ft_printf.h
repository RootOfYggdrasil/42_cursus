/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:09:08 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/03/31 21:27:31 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_printf_flags
{
	size_t	width;
	size_t	precision;
	bool	iszero;
	bool	isminus;
	bool	ishashtag;
	bool	isspace;
	bool	isplus;
	bool	iswidth;
	bool	isprecision;
	bool	pe;
	char	conv;
}				t_pf_flags;

// function in ft_printf.c
int		ft_printf(const char *input, ...);
int		p_conv(const char conv, va_list args, size_t length, t_pf_flags flag);
void	flag_initialize(t_pf_flags *flag);
// function in char.c
int		print_0(int n);
int		print_perc(void);
int		print_putchar(char c, int fd);
int		print_char(t_pf_flags flag, char c, int fd);
int		print_str(t_pf_flags flag, char *s, int fd, int i);
// function in int_conv.c
int		print_int(t_pf_flags flag, int nbr, int i, int count);
int		print_int_midhandler(t_pf_flags flag, int nbr, int i);
int		print_unsint(t_pf_flags flag, unsigned int nbr, int i, int count);
// function in width_handler.c
int		print_space_w(int n);
// function in nbr_print.c
int		count_nbrdigit(int n, int base);
int		print_nbr(long int n, int out);
int		print_sign(t_pf_flags flag, int nbr);
int		print_unsnbr(unsigned int n, int out);
int		count_unsnbrdigit(unsigned long n, int base);
// function in hex_conv.c
int		print_zerox(char conv);
int		print_int_to_hex(unsigned int n, const char c, int out);
int		print_l_to_hex(unsigned long n, const char c, int out);
//int		print_hex(t_pf_flags flag, int nbr);
//int		print_pointer(t_pf_flags flag, unsigned long nbr);
// function in flag.c
//void    search_conv(const char* s, va_list args, size_t* i, t_pf_flags* flag);
//void    search_flag(const char* s, va_list args, size_t* i, t_pf_flags* flag);
int		flag_conv(const char *s, va_list args, t_pf_flags *flag, int *i);
//
int		print_nbrhex(unsigned int n, const char c, int out);
int		print_int_unsmidhandler(t_pf_flags flag, unsigned int nbr, int i);

void	reduceto25i(t_pf_flags flag, int nbr, int *count, int i);

int		print_hex(t_pf_flags flag, int nbr, int count, int i);
int		print_pointer(t_pf_flags flag, unsigned long nbr, int count, int i);
#endif

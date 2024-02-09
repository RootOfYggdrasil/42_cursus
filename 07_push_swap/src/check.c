/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:29:55 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/11/20 11:27:07 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_minmax(long tmp)
{
	if (tmp < -2147483648 || tmp > 2147483647)
		return (1);
	return (0);
}

int	ft_check_dup(long n, char **args, int i)
{
	while (args[i])
	{
		if (ft_atoi_long(args[i++]) == n)
			return (1);
	}
	return (0);
}

void	ft_check_args(int ac, char **av)
{
	int		i;
	long	tmp;
	char	**sp;

	i = 0;
	if (ac == 2)
		sp = ft_split(av[0], ' ');
	else
		sp = av;
	if (*sp == NULL)
		stderr_exit("Error\n");
	while (sp[i])
	{
		tmp = ft_atoi_long(sp[i]);
		if (!ft_isnum(sp[i]) || ft_check_dup(tmp, sp, i + 1)
			|| ft_minmax(tmp))
		{
			if (ac == 2)
				ft_free(sp);
			stderr_exit("Error\n");
		}
		i++;
	}
	if (ac == 2)
		ft_free(sp);
}

void	stderr_exit(const char *s)
{
	write(2, s, ft_strlen(s));
	exit(0);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
	{
		i++;
		if (!num[1])
			return (0);
	}
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

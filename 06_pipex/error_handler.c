/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:13:13 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/11/06 11:05:21 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/pipex.h"
/*  perror This is not the appropriate use of the perror function, as it is 
used to print a description of the error that occurred during a system call. 
In this case, the error is not related to a system call, so using perror does 
not make sense. It would be better to use a different function, such as stderr 
to print an error message. */

/* call write on STDERR with the message and exit*/
void	stderr_exit(const char *s)
{
	write(2, s, ft_strlen(s));
	exit (1);
}

/* call write on STDERR with the message and
 exit with exit errore "command not found"*/
void	stderr_exit_cmd(const char *s)
{
	write(2, s, ft_strlen(s));
	exit (127);
}

/*  Call perror and exit with exit(1) = false, we can add more thing if we want
    also to print somewhere or do something with error */
void	perror_exit(const char *s)
{
	perror(s);
	exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:42:06 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/11/05 20:49:11 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"
#include "includes/libft.h"

/* malloc fd for the pipe and pipe them 
void	create_pipes(t_pipex *px)
{
	size_t	i;

	i = 0;
	px->fd_pipe = (int *)malloc(px->cmd_nbr * 2 * sizeof(int));
	if (!px->fd_pipe)
		perror_exit("ALLOCAZIONE FD ERRORE");
	while (i < px->cmd_nbr - 1)
	{
		if (pipe(px->fd_pipe[i * 2]) == -1)
			perror_exit("PIPE ERRORE"); 
			PROBABILMENTE BISOGNA FREE THE PIPE DA AGGIUNGERE NEL CASO
	}
}

*/
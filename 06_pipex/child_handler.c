/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:09:29 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/11/05 11:19:39 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/pipex.h"
/* X  pipex bonus
 set with dup fd0 to stdin and fd1 to stdout 
void    dup_set(int fd0, int fd1)
{
	dup2(fd0, STDIN_FILENO);
	dup2(fd1, STDOUT_FILENO);
}

 handle the dup with the fd, infile or outfile 
void    dup_handler(t_pipex *px)
{
    if (px->pid == 0)
        dup_set(px->infile, px->fd_pipe[(px->pid * 2) + 1]);
    else if (px->pid == px->pipe_nbr)
        dup_set(px->fd_pipe[px->pid * 2], px->outfile);
    else
        dup_set(px->fd_pipe[px->pid * 2], px->fd_pipe[(px->pid * 2) + 1]);
    
}

 create child, call dup, call command_handler 
void    child_create(t_pipex *px)
{
    int   pid;
    
    pid = fork();   
    if (pid < 0)
        perror_exit("CHILD PID ERROR");
    if (pid == 0)
    {
        dup2(px->fd_pipe[px->cid * 2], STDOUT_FILENO);
        close(px->fd_pipe[px->cid * 2]);
        close((px->cid * 2) + 1);
        
        //command_handler(px);
    }
    px->cid++;
}*/
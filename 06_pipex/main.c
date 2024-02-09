/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:34:19 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/11/05 20:48:09 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/pipex.h"

// ad ogni errore andra freeata la memoria???   
/*open, close, read, write,
malloc, free, perror,
strerror, access, dup, dup2,
execve, exit, fork, pipe,
unlink, wait, waitpid

$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2

$> ./pipex here_doc LIMITER cmd cmd1 file

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
	creazione pipe
	gestione pipe


*/

/*
int	main(int argc, char *argv[], char *envp[])
{
	t_pipex pipe;

	if (argc < 5)
		stderr_exit("Wrong Number Of Argument");
	pipe.ishd = ft_strncmp(argv[1], "here_doc", 8);
	if (argc < 6 && !pipe.ishd)
		stderr_exit("Wrong Number Of Argument");
	if (pipe.ishd)
		pipe.outfile = open_file(argv[argc - 1], 1);
	else
		pipe.outfile = open_file(argv[argc - 1], 0);
	//pipex gestione
	if (envp && pipe.outfile)
	{
		pipe.ishd = pipe.ishd;
	}
	
	return (0);
}*/

void	exec_child(t_pipex *pipex)
{
	dup2(pipex->fd[1], 1);
	dup2(pipex->infile, 0);
	close(pipex->fd[0]);
	close(pipex->outfile);
}

void	exec_parent(t_pipex *pipex)
{
	dup2(pipex->fd[0], 0);
	dup2(pipex->outfile, 1);
	close(pipex->fd[1]);
	close(pipex->infile);
}

void	ft_exec(t_pipex *px, char *envp[], char *cmd)
{
	px->cmd_args = cmd;
	path_finder(px, envp);
	command_handler(px, envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;
	int		pid_child;

	if (argc != 5)
		stderr_exit("Wrong Number Of Argument\n");
	pipex.infile = ft_open_file(argv[1], 2);
	pipex.outfile = ft_open_file(argv[4], 0);
	if (pipe(pipex.fd) == -1)
		perror_exit("Pipe Fail\n");
	pid_child = fork();
	if (pid_child == -1)
		perror_exit("Fork Fail\n");
	if (pid_child == 0)
	{
		exec_child(&pipex);
		ft_exec(&pipex, envp, argv[2]);
	}
	waitpid(pid_child, NULL, 0);
	exec_parent(&pipex);
	ft_exec(&pipex, envp, argv[3]);
	return (0);
}

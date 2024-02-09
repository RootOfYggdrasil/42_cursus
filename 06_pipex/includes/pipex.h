/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:14:22 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/11/06 11:05:25 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/*	cid = process child id 
	infile = fd in file
	outfile = fd out file
	fd_pipe = (cmd-1)*2 fd connected with pipe
	cmd_path = all the path where to search the command
	cmd_nbr = number of the command to handle

*/
/*
typedef struct s_pipex
{
	int		cid;
	int		infile;
	int		outfile;
	int		ishd;
	int		pipe_nbr;
	int		*fd_pipe;
	int		path_nbr;
	char	**cmd_path;
	char	*cmd;
	char	*cmd_args;
	pid_t	pid;
	int		cmd_nbr;
}t_pipex;*/

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		fd[2];
	int		path_nbr;
	char	**cmd_path;
	char	*cmd;
	char	*cmd_args;
}				t_pipex;

void	path_finder(t_pipex *px, char **envp);
void	command_handler(t_pipex *px, char **envp);

int		ft_open_file(char *ffp, int flag);
/* pipe_handler.c */

/* error_handler.c */
void	stderr_exit(const char *s);
void	perror_exit(const char *s);

/* file_handler.c */
void	open_outfile(char *file, t_pipex *px);
void	open_infile(char *file, t_pipex *px);

void	stderr_exit_cmd(const char *s);
#endif
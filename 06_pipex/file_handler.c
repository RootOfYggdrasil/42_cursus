/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:56:45 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/11/06 11:05:14 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/pipex.h"

/* function to open infile */
void	open_infile(char *file, t_pipex *px)
{
	px->infile = open(file, O_RDONLY);
	if (px->infile == -1)
		perror_exit("INFILE ERRORE");
}

/* open or create the outfile, require filename 
    and pipex info to set fd to outfile */
void	open_outfile(char *file, t_pipex *px)
{
	px->outfile = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (px->outfile == -1)
		perror_exit("OUTFILE ERRORE");
}

int	ft_open_file(char *ffp, int flag)
{
	int	file;

	file = 0;
	if (flag == 0)
	{
		file = open(ffp, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (access(ffp, F_OK | R_OK) == -1)
			stderr_exit("Error OutFile");
	}
	else if (flag == 1)
		file = open(ffp, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (flag == 2)
	{
		file = open(ffp, O_RDONLY, 0644);
		if (access(ffp, F_OK | W_OK) == -1)
			stderr_exit("Error Infile");
	}
	if (file == -1 || access(ffp, F_OK | R_OK))
		stderr_exit("Error File");
	return (file);
}

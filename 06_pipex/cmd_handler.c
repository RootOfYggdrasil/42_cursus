/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdel-gra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:02:23 by sdel-gra          #+#    #+#             */
/*   Updated: 2023/11/06 11:04:12 by sdel-gra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"
#include "includes/libft.h"

char	*ft_free(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (*ptr);
}

void	ft_free_tutto(t_pipex *px, char ***cmd, char **cmd_path)
{
	int	i;

	i = 0;
	ft_free(cmd_path);
	while (px->cmd_path[i])
	{
		ft_free(px->cmd_path + i);
		i++;
	}
	i = 0;
	while ((*cmd)[i])
	{
		ft_free((*cmd) + i);
		i++;
	}
	if (px->cmd_path)
		free(px->cmd_path);
	if (*cmd)
		free(*cmd);
}

/* path similar to:
    PATH=/nfs/homes/sdel-gra/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:
	/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
    */
/*  search PATH= in the first 5 bytes 
    split it and put on px->cmd_path*/
void	path_finder(t_pipex *px, char **envp)
{
	char	**tmp;
	char	*tofree;
	int		i;

	i = 0;
	tmp = envp;
	while (tmp && ft_strncmp("PATH=", *tmp, 5))
		tmp++;
	px->cmd_path = ft_split((*tmp) + 5, ':');
	while (px->cmd_path[i])
	{
		tofree = px->cmd_path[i];
		px->cmd_path[i] = ft_strjoin(px->cmd_path[i], "/");
		ft_free(&tofree);
		i++;
	}
}
/*
void	path_handler_cmd(t_pipex *px)
{
    
}*/

/*  */
void	command_handler(t_pipex *px, char **envp)
{
	char	**cmd;
	char	*cmd_path;
	int		i;

	i = 0;
	cmd = ft_split(px->cmd_args, ' ');
	while (px->cmd_path[i])
	{
		cmd_path = ft_strjoin(px->cmd_path[i], cmd[0]);
		if (access(cmd_path, F_OK | X_OK) == 0)
			break ;
		else
			ft_free(&cmd_path);
		i++;
	}
	if (!cmd_path)
	{
		ft_free_tutto(px, &cmd, &cmd_path);
		stderr_exit_cmd("command not found\n");
	}
	if (execve(cmd_path, cmd, envp) == -1)
		write(1, "errore execve\n", 14);
}

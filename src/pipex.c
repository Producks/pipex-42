/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:11:28 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/05 22:32:13 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	ft_main(t_pipex pip, char *argv[], char *envp[])
{
	pip.i = -1;
	close(pip.fd[1]);
	dup2(pip.fd[0], 0);
	dup2(pip.outfile_fd, 1);
	pip.argv_cmd = ft_split(argv[3], ' ');
	if (!pip.argv_cmd)
		split_error(&pip);
	while (pip.path_cmd[++pip.i])
	{
		pip.command = ft_strjoin(pip.path_cmd[pip.i], pip.argv_cmd[0], '/');
		if (!pip.command)
			break ;
		if (!access(pip.command, 0))
		{
			ft_free(pip.path_cmd);
			execve(pip.command, pip.argv_cmd, envp);
			error_execve(&pip);
		}
		free(pip.command);
	}
	close(1);
	command_error(&pip);
}

static void	ft_fork(t_pipex pip, char *argv[], char *envp[])
{
	pip.i = -1;
	close(pip.fd[0]);
	dup2(pip.fd[1], 1);
	dup2(pip.infile_fd, 0);
	pip.argv_cmd = ft_split(argv[2], ' ');
	if (!pip.argv_cmd)
		split_error(&pip);
	while (pip.path_cmd[++pip.i])
	{
		pip.command = ft_strjoin(pip.path_cmd[pip.i], pip.argv_cmd[0], '/');
		if (!pip.command)
			break ;
		if (!access(pip.command, 0))
		{
			ft_free(pip.path_cmd);
			execve(pip.command, pip.argv_cmd, envp);
			error_execve(&pip);
		}
		free(pip.command);
	}
	close(1);
	command_error(&pip);
}

static void	ft_get_path(t_pipex *pip, char *envp[])
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	pip->path = (*envp + 5);
	pip->path_cmd = ft_split(pip->path, ':');
	if (!pip->path_cmd)
		close_fds(pip, "Split");
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pip;

	if (argc != 5)
		return (printf("Wrong number of arguments!\n"), 1);
	open_error_check(&pip, argv);
	if (pipe(pip.fd) == FAIL)
		close_fds(&pip, "pipe");
	ft_get_path(&pip, envp);
	if (pip.pid < 0)
		ft_main(pip, argv, envp);
	pip.pid = fork();
	if (pip.pid == 0)
		ft_fork(pip, argv, envp);
	if (pip.pid > 0)
	{
		waitpid(pip.pid, NULL, 0);
		ft_main(pip, argv, envp);
	}
	ft_free(pip.path_cmd);
	close_fds(&pip, "fork");
}

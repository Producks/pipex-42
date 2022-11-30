/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:11:28 by ddemers           #+#    #+#             */
/*   Updated: 2022/11/28 20:56:54 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	ft_main(s_pipex *pip, char *argv[], char *envp[])
{
	exit(0);
}

static void	ft_fork(s_pipex pip, char *argv[], char *envp[])
{
	close(pip.fd[0]);
	dup2(pip.fd[1], 1);
	dup2(pip.infile_fd, 0);
	pip.argv_cmd = ft_split(argv[3], ' '); // {"ls", "-la", NULL}

	exit(0);
}

static char	**ft_get_path(s_pipex *pip, char *envp[])
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	pip->path = (*envp + 5);
	pip->path_cmd = ft_split(pip->path, ':');
	if (!pip->path_cmd)
	{
		close(pip->infile_fd);
		close(pip->outfile_fd);
		perror("Split: ");
		exit(1);
	}
	return (pip->path_cmd);
}

int	main(int argc, char *argv[], char *envp[])
{
	s_pipex pip;

	if (argc != 5)
		return (printf("Wrong number of arguments!\n"), 1);
	open_error_check(&pip, argv);
	if (pipe(pip.fd) == FAIL)
		return (perror("pipe"), close(pip.infile_fd), close(pip.outfile_fd), 1);
	pip.path_cmd = ft_get_path(&pip, envp);
	pip.pid = fork();
	// if (pip.pid == 0)
	// 	ft_fork(pip, argc, envp);
	// else if (pip.pid > 0)
		// ft_main(&pip, argc, envp);
	return (perror("fork"), close(pip.infile_fd), close(pip.outfile_fd), 1);
}

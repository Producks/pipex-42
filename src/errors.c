/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 04:52:58 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/05 22:38:48 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	split_error(t_pipex *pip)
{
	close(pip->infile_fd);
	close(pip->outfile_fd);
	ft_free(pip->argv_cmd);
	perror("Split");
	exit(1);
}

void	command_error(t_pipex *pip)
{
	ft_free(pip->argv_cmd);
	ft_free(pip->path_cmd);
	close(pip->infile_fd);
	close(pip->outfile_fd);
	perror("command not found");
	exit(1);
}

void	error_execve(t_pipex *pip)
{
	close(pip->infile_fd);
	close(pip->outfile_fd);
	free(pip->command);
	ft_free(pip->argv_cmd);
	perror("command not found");
	exit(1);
}

void	close_fds(t_pipex *pip, char *str)
{
	close(pip->infile_fd);
	close(pip->outfile_fd);
	perror(str);
	exit(1);
}

void	open_error_check(t_pipex *pip, char *argv[])
{
	pip->infile_fd = open(argv[1], O_RDONLY);
	if (pip->infile_fd == FAIL)
	{
		perror("pipex: input");
		pip->pid = -1;
	}
	pip->outfile_fd = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	printf("%d", pip->outfile_fd);
	if (pip->outfile_fd == FAIL)
	{
		perror("output");
		close(pip->infile_fd);
		exit(1);
	}
}

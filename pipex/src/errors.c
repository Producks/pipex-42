/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 04:52:58 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/02 23:11:55 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	close_fds(s_pipex *pip, char *str)
{
	close(pip->infile_fd);
	close(pip->outfile_fd);
	perror(str);
	exit(1);
}

void	open_error_check(s_pipex *pip, char *argv[])
{
	pip->infile_fd = open(argv[1], O_RDONLY);
	if (pip->infile_fd == FAIL)
	{
		pip->outfile_fd = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0644);
		if (pip->outfile_fd != FAIL)
		{
			write(pip->outfile_fd, "0\n", 2);
			close(pip->outfile_fd);
		}
		perror("pipex: line 1: input");
		exit(1);
	}
	pip->outfile_fd = open(argv[4], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (pip->outfile_fd == FAIL)
	{
		perror("input");
		close(pip->infile_fd);
		exit(1);
	}
}

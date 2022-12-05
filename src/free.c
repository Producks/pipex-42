/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 07:56:46 by ddemers           #+#    #+#             */
/*   Updated: 2022/12/04 23:52:45 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return ;
}

void	ft_child_free(t_pipex *pip)
{
	ft_free(pip->argv_cmd);
	ft_free(pip->path_cmd);
	close(pip->infile_fd);
	close(pip->outfile_fd);
	perror("command not found");
	exit(1);
}

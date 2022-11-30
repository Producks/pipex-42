/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:11:58 by ddemers           #+#    #+#             */
/*   Updated: 2022/11/27 14:11:58 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//Printf, perror
# include <stdio.h>
//exit
# include <stdlib.h>
//open, malloc
# include <fcntl.h>
/*Write, pipe, fork, dup2, access, execve, close
read, write*/
# include <unistd.h>

# define WRITE_END	1
# define READ_END	0
# define FAIL		-1

typedef struct var
{
	int		fd[2];
	int		infile_fd;
	int		outfile_fd;
	int		inc;
	pid_t	pid;
	char	*path;
	char	**path_cmd;
	char	**argv_cmd;
}s_pipex;

typedef struct cmd
{
	
}cmds;

//pipex_strings.c
void	*ft_calloc(size_t nitems, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2, char sep);
//ft_split.c
char	**ft_split(char const *s, char c);

#endif
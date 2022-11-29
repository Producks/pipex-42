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

int	main(int argc, char *argv[], char *envp[])
{
	var test;
	char *child[] = {"/bin/ls", "-la", NULL};
	char *parent[] = {"/usr/bin/wc", "-l", NULL};

	if (argc != 5)
		return (printf("Wrong number of arguments!"), 0);
	if (pipe(test.fd) == FAIL)
		return (perror("pipe"), 0);
	test.pid = fork();
	if (test.pid == 0)
	{
		close(test.fd[0]);
		dup2(test.fd[1], 1);
		close(test.fd[1]);
		if (execve(child[0], child, envp) == FAIL)
			perror("execve");
		exit (0);
	}
	else if (test.pid > 0)
	{
		wait(NULL);
		close(test.fd[1]);
		dup2(test.fd[0], 0);
		close(test.fd[0]);
		if (execve(parent[0], parent, envp) == FAIL)
			perror("execve");
		exit (0);
	}
	return (perror("fork"), 0);
	argv++;
	envp++;
}

// int	main(int argc, char *argv[], char *envp[])
// {
// 	pid_t	pid;
// 	int		fd[2];
// 	char *child[] = {"/bin/ls", "-la", NULL};
// 	char *parent[] = {"/usr/bin/wc", "-l", NULL};
// 	if (argc == 5)
// 		return (printf("Wrong number of arguments!"), 0);
// 	if (pipe(fd) == FAIL)
// 		return (perror("pipe"), 0);
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		close(fd[0]);
// 		dup2(fd[1], 1);
// 		close(fd[1]);
// 		printf("Child process");
// 		if (execve(child[0], child, envp) == FAIL)
// 			perror("execve");
// 		exit (0);
// 	}
// 	else if (pid > 0)
// 	{
// 		wait(NULL);
// 		close(fd[1]);
// 		dup2(fd[0], 0);
// 		close(fd[0]);
// 		if (execve(parent[0], parent, envp) == FAIL)
// 			perror("execve");
// 		exit (0);
// 	}
// 	return (perror("fork"), 0);
// 	argv++;
// 	envp++;
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemers <ddemers@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:11:28 by ddemers           #+#    #+#             */
/*   Updated: 2022/11/27 15:22:03 by ddemers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int main(int argc, char *argv[], char *envp[])
{
    int i;
    char *argVec[] = {"ls -la", NULL};

    i = 0;
    while (ft_strncmp("PATH", *envp, 4))
        envp++;
    argv++;
    execve("/bin/ls", argv, envp);
    perror("Error execve");
    return (0);
}
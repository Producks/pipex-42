#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int fork_pid;
    int last_pid = 0;
    int a;


    printf("First%d:\n", getpid());
    for(int i = 0; i < 5; i++)
    {
        fork_pid = fork();
        if (fork_pid != 0)
        {
            waitpid(fork_pid, NULL, 0);
            printf("Child:%d\n", fork_pid);
        }
        else
            exit(69);    
    }
   // waitpid(fork_pid, NULL, 0);
    //printf("%d\n", getpid());
    exit(1);
}
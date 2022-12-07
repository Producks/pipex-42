```sh
cd dillinger
npm i
node app
```
Man: https://linux.die.net/man/2/dup2  
Prototype: int dup2(int oldfd, int newfd);  
Use: Restore FD from dup 1  
  
### execve  
Man: https://linux.die.net/man/2/execve  
Prototype: int execve(const char *filename, char *const argv[], char *const envp[]);  
Use: execve() executes the program pointed to by filename. filename must be either a binary executable, or a script starting with a line of the form:
***Notes int main(int argc, char *argv[], char *envp[])***

### exit  
Man: https://linux.die.net/man/3/exit  
Prototype: void exit(int status);  
Use: The exit() function causes normal process termination and the value of status & 0377 is returned to the parent  
  
### fork  
Man: https://linux.die.net/man/2/fork  
Prototype: pid_t fork(void);  
Use: fork() creates a new process by duplicating the calling process. The new process, referred to as the child, is an exact duplicate of the calling process, referred to as the parent, except for the following points:  
  
### pipe  
Man: https://linux.die.net/man/2/pipe  
Prototype: int pipe(int pipefd[2]);  
Use: ???

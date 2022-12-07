# pipex  
Hello
# Allowed functions:
open, close, read, write,
malloc, free, perror,
strerror, access, dup, dup2,
execve, exit, fork, pipe, printf  
Libft ✔️

# Notes for new functions:
### pipe  
Man: https://linux.die.net/man/2/pipe  
Prototype: int pipe(int pipefd[2]);  
Use: https://tldp.org/LDP/lpg/node9.html  

### perror  
Man: https://linux.die.net/man/3/perror  
Prototype: void perror(const char *s);  
Use:Prints a textual description of the error code currently stored in the system variable errno to stderr.  
**Notes https://en.cppreference.com/w/cpp/error/errno**  

### access  
Man: https://linux.die.net/man/2/access  
Prototype: int access(const char *pathname, int mode);  
Use:  
access() checks whether the calling process can access the file pathname. If pathname is a symbolic link, it is dereferenced.
On success (all requested permissions granted), zero is returned. On error (at least one bit in mode asked for a permission that is denied, or some other error occurred), -1 is returned, and errno is set appropriately.  
  
### dup2  
Man: https://linux.die.net/man/2/dup2  
Prototype: int dup2(int oldfd, int newfd);  
Use: Restore FD from dup 1  
  
### execve  
Man: https://linux.die.net/man/2/execve  
Prototype: int execve(const char *filename, char *const argv[], char *const envp[]);  
Use: execve() executes the program pointed to by filename. filename must be either a binary executable, or a script starting with a line of the form:
**Note int main(int argc, char *argv[], char *envp[])****

### exit  
Man: https://linux.die.net/man/3/exit  
Prototype: void exit(int status);  
Use: The exit() function causes normal process termination and the value of status & 0377 is returned to the parent  
  
### fork  
Man: https://linux.die.net/man/2/fork  
Prototype: pid_t fork(void);  
Use: fork() creates a new process by duplicating the calling process. The new process, referred to as the child, is an exact duplicate of the calling process, referred to as the parent.

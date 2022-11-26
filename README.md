# pipex

# Allowed functions:
open, close, read, write,
malloc, free, perror,
strerror, access, dup, dup2,
execve, exit, fork, pipe, printf
Libft ✔️

# Description of new functions:
perror  
Man: https://linux.die.net/man/3/perror  
Prototype: void perror(const char *s);  
Use:Prints a textual description of the error code currently stored in the system variable errno to stderr.  
****Notes https://en.cppreference.com/w/cpp/error/errno ****  
  
strerror  
Man: https://linux.die.net/man/3/strerror  
Prototype: char *strerror(int errnum);  
Use: The strerror() function returns a pointer to an error message string that corresponds to the specified error number. The argument value is usually that of the errno variable, but can be any integer value. The string pointed to by the return value of strerror() may change on successive strerror() calls.  

access  
Man: https://linux.die.net/man/2/access  
Prototype: int access(const char *pathname, int mode);  
Use:  
access() checks whether the calling process can access the file pathname. If pathname is a symbolic link, it is dereferenced.
On success (all requested permissions granted), zero is returned. On error (at least one bit in mode asked for a permission that is denied, or some other error occurred), -1 is returned, and errno is set appropriately.  
  
dup  
Man: https://linux.die.net/man/3/dup  
Prototype: int dup(int fildes);  
Use: Make copy of FD

dup2
Man: https://linux.die.net/man/2/dup2
Prototype: int dup2(int oldfd, int newfd);
Use: Restore FD from dup 1

execve
Man: https://linux.die.net/man/2/execve
Prototype: int execve(const char *filename, char *const argv[], char *const envp[]);
Use: execve() executes the program pointed to by filename. filename must be either a binary executable, or a script starting with a line of the form:
***Notes int main(int argc, char *argv[], char *envp[])***


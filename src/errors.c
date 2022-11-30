#include "../inc/pipex.h"

void    open_error_check(s_pipex *pip, char *argv[])
{
    pip->infile_fd = open(argv[1], O_RDONLY);
    if (pip->infile_fd == FAIL)
    {
        perror("Open first file argv problem:");
        exit(1);
    }
    pip->outfile_fd = open(argv[4], O_WRONLY);
    if (pip->outfile_fd == FAIL)
    {
        perror("Open fourth file argv problem:");
        close(pip->infile_fd);
        exit(1);
    }
}
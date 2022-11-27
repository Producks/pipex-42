#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    int fd;

    fd = open("lol", "r");
    printf("%s", strerror(69));
    exit(-1);
}
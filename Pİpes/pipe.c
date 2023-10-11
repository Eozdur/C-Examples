#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    int pipe_fd[2];
    int pid;
    if(pipe(pipe_fd) == -1)
    {
        printf("Pipe error :( \n");
        return 0;
    }
    pid = fork();
    if(pid == -1)
    {
         printf("Fork error \n");
         return 0;
    }
    if(pid == 0)
    {
        close(pipe_fd[0]);
        int x;
        printf("LÜtfen bir sayi giriniz :");
        scanf("%d",&x);
        if(write(pipe_fd[1],&x,sizeof(int)) == -1)
        {
            printf("Error writing \n");
            return 0;
        }
        close(pipe_fd[1]);
    }
    else
    {
        close(pipe_fd[1]);
        int y;
        if(read(pipe_fd[0],&y,sizeof(int)) == -1)
        {
            printf("Error reading \n");
            return 0;
        }
        y = y*3;
        close(pipe_fd[0]);
        printf("ALinan sayi %d\n",y);
    }
}
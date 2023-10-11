#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void leaf()
{
    char file_name[20];
    sprintf(file_name,"%d.txt",getpid());
    FILE *fp=fopen(file_name,"w");
    srand(getpid());
    fprintf(fp,"%d",(rand() % 100));
    fclose(fp);
}
void parent(int pid1,int pid2)
{
    wait(NULL);
    char file_name1[20];
    sprintf(file_name1,"%d.txt",pid1);
    char file_name2[20];
    sprintf(file_name2,"%d.txt",pid2);
    char file_name3[20];
    sprintf(file_name3,"%d.txt",getpid());
    FILE *fp1,*fp2,*fp3;
    fp1=fopen(file_name1,"r");
    fp2=fopen(file_name2,"r");
    int left,right;
    fscanf(fp1,"%d",&left);
    fscanf(fp2,"%d",&right);
    fclose(fp1);
    fclose(fp2);
    fp3=fopen(file_name3,"w");
    fprintf(fp3,"%d",left+right);
    fclose(fp3);
}
void add_tree(int n)
{
    if(n == 0)
    {
        leaf();
        return;
    }
    int pid,pid2;
    pid = fork();
    if(pid > 0)
    {
        pid2=fork();
        if(pid2>0)
        {
            wait(NULL);
            printf("Parent : %d, c1:%d,c2:%d\n",getpid(),pid,pid2);
            fflush(stdout);
            parent(pid,pid2);

        }
        else if(pid2 == 0)
        {
            add_tree(--n);
        }
    }
    else if(pid == 0)
    {
        add_tree(--n);
    }
}
int main()
{
    add_tree(3);
    return 0;
}

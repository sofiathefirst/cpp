#include <unistd.h>
#include <signal.h>
#include <cstdio>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
int main()
{
    pid_t pid;
    int status;
    if(!(pid= fork()))
    {
        //printf("Hi I am child process!\n");
        printf("in child kill, pid = %d\n", getpid()); 
        execlp("./hello1","3","6","123a","555",(char*)NULL);
        std::cout<<"child p over\n";
        sleep(10);
        return 0;
    }
    else
    {
        printf("send signal to child process (%d) \n", pid);
        sleep(5);
        kill(pid, SIGABRT);
        wait(&status);
        if(WIFSIGNALED(status))
            printf("chile process receive signal %d\n", WTERMSIG(status));
    }
}

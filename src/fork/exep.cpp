#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/wait.h>
 using namespace std;
int main(int argc , char *argv[])
{
int status=0;
pid_t pid = fork();

if (pid == 0) {
    execlp("./hello1","3","6","123a","555",(char*)NULL);std::cout<<"child p over\n";
}
else if (pid > 0) {
    waitpid(pid, &status, 0);

    WEXITSTATUS(status);
printf("status=%d\n",WEXITSTATUS(status));
}
else { 
/* fork() error */ 
std::cout<<"ERROR\n";
}

    return 0;
}


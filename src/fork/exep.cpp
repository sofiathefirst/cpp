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

  char * argv[] = {"record", "-a", "&"};
 printf("in child kill, pid = %d\n", getpid()); 
   // execlp("/opt/ros/kinetic/lib/rosbag/record","record","-a",(char *)NULL);
execlp("./hello1","11","22","333","444",(char*)NULL);std::cout<<"child p over\n";

   // system("rosbag record -a");
}
else if (pid > 0) {
sleep(15);
    //waitpid(pid, &status, 0);
kill(pid+3,SIGINT);
    WEXITSTATUS(status);
printf("status=%d\n",WEXITSTATUS(status));
}
else { 
/* fork() error */ 
std::cout<<"ERROR\n";
}

    return 0;
}


#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void) 
{ 
printf("before fork(), pid = %d\n", getpid()); 
pid_t p1 = fork(); 
if( p1 == 0 )
{ 
printf("in child 1, pid = %d\n", getpid()); 
return 44; //若此处没有return 0 p1 进程也会执行 pid_t p2=fork()语句
} 
pid_t p2 = fork(); 
if( p2 == 0 ) 
{ 
printf("in child 2, pid = %d\n", getpid()); 

return 120; //子进程结束，跳回父进程
printf("hello world\n");//没有打印
}
int st1, st2; 
waitpid( p1, &st1, 0); 
waitpid( p2, &st2, 0); 
printf("in parent, child 1 pid = %d\n", p1); 
printf("in parent, child 2 pid = %d\n", p2); 
printf("in parent, pid = %d\n", getpid()); 
printf("in parent, child 1 exited with %d\n", WEXITSTATUS(st1)); 
printf("in parent, child 2 exited with %d\n", WEXITSTATUS(st2)); 
return 0; 
} 
 
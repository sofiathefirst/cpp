#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
 
int main(){
 const char *file_name = ".";
 char abs_path_buff[PATH_MAX];
 
 //获取文件路径, 填充到abs_path_buff
 //realpath函数返回: null表示获取失败; 否则返回指向abs_path_buff的指针
 if(realpath(file_name, abs_path_buff)){
  printf("%s %s\n", file_name, abs_path_buff);
 }
 else{
  printf("the file '%s' is not exist\n", file_name); 
 }
 
 return 0;
}

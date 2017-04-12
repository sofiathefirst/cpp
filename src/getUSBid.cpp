#include <iostream>  
#include <fstream>  
#include <cstring>
#include <string>
using namespace std;
//char buf
char get_ttyUSB_id(const char* physical_id)
{
  char cmd[256] = "ls -l /sys/class/tty/ | grep 00:05";
  //strcat(cmd, physical_id);
  FILE *fp = popen(cmd, "r");
  char buf[256];
  fgets(buf, sizeof(buf), fp); 
  pclose(fp);
  printf("port_id:%s,   %s\n", physical_id, buf);

  char  *ind = strstr(buf, "ttyS");
  if(ind)
  {
    std::cout<<*(ind+4)<<endl;
    return *(ind+4);
  }
  return NULL;
}

int main( )
{     
  const char *fpga_physical_id = "1-3";     
  char  fpga_ttyUSB_id = get_ttyUSB_id(fpga_physical_id); 
  std::cout<<fpga_ttyUSB_id<<endl;
char strs[]="/dev/ttyUSB0";
 strs[11]='4';
std::cout<<strs<<endl;
std::string s=strs;
std::cout<<s<<endl;
  return 0;
}


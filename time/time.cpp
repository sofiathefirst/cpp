#include <iostream>  
#include <sys/time.h>
#include <cstdlib>  
#include <cstdio>
#include <ctime>
#include <cmath>
#include <unistd.h>

using namespace std;
time_t clocktime()
{

struct timeval tv;  
     gettimeofday(&tv,NULL); 
std::cout<<tv.tv_sec<<endl;
std::cout<<tv.tv_usec<<endl;


struct timespec tn;

cout<<"----";
clock_gettime(CLOCK_REALTIME, &tn);

std::cout<<tn.tv_nsec<<endl;
std::cout<<tn.tv_sec<<endl;
	//sleep(1);

cout<<"----";
double a = tv.tv_sec + tv.tv_usec/1000000.;
std::cout<<a<<"double"<<endl;
	time_t le=time(NULL);  
std::cout<<le<<endl;
//	clock_t end   = clock();  

//	cout<<"clock"<<end - start<<"time"<<le-lt<<endl<<start<<endl<<lt<<endl;  

struct tm *tmday=localtime(&le);
cout<<tmday->tm_year<<",";
cout<<tmday->tm_mon<<",";
cout<<tmday->tm_mday<<",";
cout<<tmday->tm_hour<<",";
cout<<tmday->tm_min<<",";
cout<<tmday->tm_sec<<",\n";
tmday->tm_hour=0;
tmday->tm_min=0;
tmday->tm_sec=0;


cout<<"stamp"<<mktime(tmday)<<endl;
//return mktime(tmday);

struct timespec current_time,last_time;
double aa=1.1234567891;
printf("double %.12f\n",aa);
cout<<"----";
clock_gettime(CLOCK_REALTIME, &last_time);
sleep(1);
std::cout<<last_time.tv_sec<<","<<last_time.tv_nsec<<endl;
clock_gettime(CLOCK_REALTIME, &current_time);
std::cout<<current_time.tv_sec<<","<<current_time.tv_nsec<<","<<pow(10,-9)<<endl;
  double delta_time = (current_time.tv_sec - last_time.tv_sec)+ (current_time.tv_nsec - last_time.tv_nsec)*pow(10,-9);
printf("double %.12f\n",delta_time);

}
int main( ){     
	clocktime();
	return 0;
}


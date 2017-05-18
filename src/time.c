#include <stdio.h>  
//include <fstream>  
//#include <cstring>
#include <time.h>
//#include <unistd.h>

//using namespace std;
time_t clocktime()
{
	//clock_t start = clock();  
	//time_t lt=time(NULL);     
	//sleep(1);
	time_t le=time(NULL);  
//	clock_t end   = clock();  

//	cout<<"clock"<<end - start<<"time"<<le-lt<<endl<<start<<endl<<lt<<endl;  

struct tm *tmday=localtime(&le);

tmday->tm_hour=0;
tmday->tm_min=0;
tmday->tm_sec=0;


//cout<<"stamp"<<mktime(tmday)<<endl;
printf("%lld\n",mktime(tmday));
return mktime(tmday);

}
int main( ){     
	clocktime();
	return 0;
}


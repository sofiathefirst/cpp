#include <iostream>  
#include <fstream>  
#include <cstring>
#include <ctime>
#include <unistd.h>

using namespace std;
void clocktime()
{
	clock_t start = clock();  
	time_t lt=time(NULL);     
	sleep(1);
	time_t le=time(NULL);  
	clock_t end   = clock();  

	cout<<"clock"<<end - start<<"time"<<le-lt<<endl<<start<<endl<<lt<<endl;  

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

}
int main( ){     
	clocktime();
	return 0;
}


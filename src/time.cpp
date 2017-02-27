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

	cout<<"clock"<<end - start<<"time"<<le-lt<<endl;  
}
int main( ){     
       clocktime();
		return 0;
}


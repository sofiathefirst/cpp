#include <stdio.h>
#include <sys/types.h>
#include <ctype.h>
#include <stdint.h>
#include<iostream>
#include <typeinfo>
using namespace std;
class complex
{
public:
	double real;
	double im;
	//int a[10];
	~complex()
	{
		printf("%f+%fiexit~\n",real,im);
	}

	complex()
	{
		printf("init\n");
	}

	complex(int  r,int i)
	{
		real=r;
		im=i;
		printf("%f+%fiinit~\n",real,im);

	}

	complex operator + (const complex &k) {
		complex c(real + k.real,im+k.im);
		printf("inner class\n");
		return c;
	}

	void operator += (const complex &k) {
		this->real += k.real;
		this->im += k.im;

		printf("inner class\n");
		return ;
	}
};



void test()
{

	complex a(3,9);
	complex b(2,-3);
	complex c=a+b;

	if(c.real==5 && c.im==6)
		printf("OK\n");
	else printf("ERROR\n");
	a+=b;
	if(a.real==5 && a.im==6)
		printf("OK\n");
	else printf("ERROR\n");
}
int main(){

	test();
    return 0;

}

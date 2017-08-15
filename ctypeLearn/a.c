#include<stdio.h>
int swp(int *a,int *b)
{
	int c=*a;
	*a = *b;
 	*b = c;
}
void pchar(const char* device)
{
	printf("%s\n",device);
}
int add(int a,int b)
{
	return a+b;
}
void test()
{
	int a=4,b=-3;
	swp(&a,&b);
	if (a==-3 && b == 4)
	printf("ok\n");
	else printf("error\n");
}
int main()
{
	test();
	return 0;
}

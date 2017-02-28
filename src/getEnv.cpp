#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main(void)
{
	char *pathvar;
	pathvar = getenv("myPath1");
	printf("pathvar=%s",pathvar);
	if (pathvar==NULL)
	pathvar="/home/b/aa22a.yaml";
	//setenv , unsetenv
	return 0;
}

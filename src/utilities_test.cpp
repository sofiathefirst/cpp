#include <iostream>
#include <iomanip>
#include <string>
#include "../include/utilities.h"
using namespace std;
using namespace zymns;
int main()
{
    if(mod(4,3)!=1) cerr<<"error"<<endl;
    if(ceil(4,3)!=2) cerr<<"error"<<endl;
    return 0;
}
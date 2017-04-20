#include <cmath>
#include <iostream>
#include <limits>  
using namespace std;

int main()
{
    cout<<"isfinite(3)="<<isfinite(3)<<",isfinite(nana)="<<isfinite(10/0.001)<<endl;
    std::cout <<std::numeric_limits<double>::max();
    return 0;
}

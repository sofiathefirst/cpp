#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    cout<<"isfinite(3)="<<isfinite(3)<<",isfinite(nana)="<<isfinite(10/0.001)<<endl;
    return 0;
}

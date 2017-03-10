
#include <iostream>
using namespace std;
 enum isacc{Acceleration=9, Deceleration,Constant_motion} vel_state;
 enum isBack{Forward=15, Back=-1} forw_back;
void set_acc(isacc d)
{

    vel_state=d;
}
void set_back(isBack d)
{
    forw_back = d;
}
int main()
{
    isBack d=Back;
    int c=Forward*13;
    cout<<Forward<<endl;
    cout<<c<<endl;
    set_back(d);
    cout<<vel_state<<endl;
    cout<<forw_back<<endl;
}

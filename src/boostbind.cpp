#include<boost/bind.hpp>   
#include<iostream>   
using namespace std;   
using namespace boost;   
  
void fun(int a,int b){   
        cout << a<<"."<<b << endl;   
}   
  
int main()   
{   
        bind(fun,1,2)();//fun(1,2)   
        bind(fun,_1,_2)(1,2);//fun(1,2)   
        bind(fun,_2,_1)(1,2);//fun(2,1)   
        bind(fun,_2,_2)(1,2);//fun(2,2)   
        bind(fun,_3,3)(1,0,-3);//fun(-3,3)   
}   

// out_of_range example
#include <iostream>       // std::cerr
#include <stdexcept>      // std::out_of_range
#include <vector>         // std::vector
using namespace std;
int main (void) {
  std::vector<int> myvector(10);
  try {
	myvector.at(8)=888;  
	std::cout<<myvector.at(8)<<endl; 
    myvector.at(888)=100;      // vector::at throws an out-of-range
	std::cout<<myvector.at(888);
  }
  catch (const std::out_of_range& oor) 
  {
    std::cerr << "Out of Range error: " << oor.what() << '\n';
  }
  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> data;
    data.push_back(2);
    data.push_back(-2);
    data.push_back(20);
    data.push_back(12);

  
  const int min = *std::min_element(data.begin(), data.end());
  const int max = *std::max_element(data.begin(), data.end());

  std::cout<<"min:="<<min<<",  max:= "<<max<<std::endl;
  return 0;

}
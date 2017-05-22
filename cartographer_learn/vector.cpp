#include <iostream>
#include <vector>
#include <string>
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

    const float mean =
    std::accumulate(data.begin(), data.end(), 0.f) / data.size();
    std::cout<<"mean:="<<mean<<std::endl;


  string result = "Count: " + std::to_string(data.size()) +
                  "  Min: " + std::to_string(min) +
                  "  Max: " + std::to_string(max) +
                  "  Mean: " + std::to_string(mean);
std::cout<<result<<endl;
    return 0;

}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple> 
using namespace std;
struct QueueKey {
  int trajectory_id;
  string sensor_id;
QueueKey(int id, string sid):trajectory_id(id),sensor_id(sid){}
  bool operator<(const QueueKey& other) const {
    return std::forward_as_tuple(trajectory_id, sensor_id) <
           std::forward_as_tuple(other.trajectory_id, other.sensor_id);
  }
};


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
                  "  Mean: " + std::to_string(mean);\


struct QueueKey q1(101,"asgld"), q2(23,"asgld");

std::cout<< (q1<q2)<<std::endl;
//std::cout<<result<<endl;
    return 0;

}
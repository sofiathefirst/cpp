#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


#include <fstream>
#include <iostream>
#include <streambuf>

using namespace std;

int main()
{
  const string filename = "/home/b/Desktop/README.md";
  std::ifstream stream(filename.c_str());
  std::string strs= string((std::istreambuf_iterator<char>(stream)),
                std::istreambuf_iterator<char>());

std::cout<<strs<<endl;
    return 0;

}
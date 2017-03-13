// type_info::name example
#include <iostream>       // std::cout
#include <typeinfo>       // operator typeid

class aatype
{
	public:
	char* type()
	{
		return "aatype";
	}
};
int main() {
  int i;
  int * pi;
  std::cout << "int is: " << typeid(int).name() << __LINE__<<','<<__FILE__<<__FUNCTION__<<'\n';
  std::cout << "  i is: " << typeid(i).name() << '\n';
  std::cout << " pi is: " << typeid(pi).name() << '\n';
  std::cout << "*pi is: " << typeid(*pi).name() << '\n';
aatype mydata;
std::cout<<mydata.type()<<std::endl;
  return 0;
}

// map::find
#include <iostream>
#include <map>
#include <vector>
//#include <pair>
using namespace std;
  struct MeasUpdateVariables
  {
    vector<int> datas;
    char c;
    unsigned int dim;
    MeasUpdateVariables(unsigned int d):dim(d){datas.resize(dim);std::cout<<dim<<endl;}
  }; //struct

int main ()
{
  std::map<char,int> mymap;
  std::map<char,int>::iterator it;

  mymap['a']=50;
  mymap['b']=100;
  mymap['c']=150;
  mymap['d']=200;

  it = mymap.find('b');
  if (it != mymap.end())
    mymap.erase (it);

  // print content:
  std::cout << "elements in mymap:" << '\n';
  std::cout << "a => " << mymap.find('a')->second << '\n';
  std::cout << "c => " << mymap.find('c')->second << '\n';
  std::cout << "d => " << mymap.find('d')->second << '\n';

  std::map<unsigned int, MeasUpdateVariables> _mapMeasUpdateVariables;
  std::map<unsigned int, MeasUpdateVariables>::iterator _mapMeasUpdateVariables_it;
vector<unsigned int> meas_dimensions;
meas_dimensions.push_back(1);
meas_dimensions.push_back(6);
meas_dimensions.push_back(3);
unsigned int meas_dimension;
    for(int i = 0 ; i< meas_dimensions.size(); i++)
    {
        // find if variables with size meas_sizes[i] are already allocated
        meas_dimension = meas_dimensions[i];
        _mapMeasUpdateVariables_it =  _mapMeasUpdateVariables.find(meas_dimension);
        if( _mapMeasUpdateVariables_it == _mapMeasUpdateVariables.end())
        {
            //variables with size z.rows() not allocated yet
            _mapMeasUpdateVariables_it = (_mapMeasUpdateVariables.insert
                (std::pair<unsigned int, MeasUpdateVariables>( meas_dimension,MeasUpdateVariables(meas_dimension) ))).first;
         }
     }

meas_dimensions.push_back(16);
meas_dimensions.push_back(31);
    for(int i = 0 ; i< meas_dimensions.size(); i++)
    {
        // find if variables with size meas_sizes[i] are already allocated
        meas_dimension = meas_dimensions[i];
        _mapMeasUpdateVariables_it =  _mapMeasUpdateVariables.find(meas_dimension);
        if( _mapMeasUpdateVariables_it == _mapMeasUpdateVariables.end())
        {
            //variables with size z.rows() not allocated yet
            _mapMeasUpdateVariables_it = (_mapMeasUpdateVariables.insert
                (std::pair<unsigned int, MeasUpdateVariables>( meas_dimension,MeasUpdateVariables(meas_dimension) ))).first;
         }
     }



     // std::map<char,int> mymap;

  // first insert function version (single parameter):
  mymap.insert ( std::pair<char,int>('a',100) );
  mymap.insert ( std::pair<char,int>('z',200) );

  std::pair<std::map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( std::pair<char,int>('z',500) );
  if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }

  return 0;
}
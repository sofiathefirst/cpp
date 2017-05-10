#include <iostream>  
 
#include <algorithm>  
 
#include <functional>  
 
#include <vector>  
  
using namespace std;  
  
  
    double median(std::vector<double> values) {
    // Return the median element of an doubles vector
    nth_element(values.begin(), values.begin() + values.size()/2, values.end());
    return values[values.size()/2];
  };
int main()  
  
{  
  vector<double>  ds;
  ds.push_back(1);
  ds.push_back(3);
  ds.push_back(-1);
std::cout<<median(ds)<<endl;
  ds.push_back(4);
std::cout<<median(ds)<<endl;
  ds.push_back(1.5);
std::cout<<median(ds)<<endl;
std::cout<<"**************8\n";
    const int VECTOR_SIZE = 50 ;  
  
    vector<int> Numbers(VECTOR_SIZE) ;  
  
    vector<int>::iterator start, end, it ;  
  
    // Initialize vector Numbers  
  
    for(int i=0;i<50;++i){   
             Numbers[i]=i;  
    }  
  
/*由于赋值时是有序的，下面random_shuffle()方法将这些数据的顺序打乱*/  
  
    random_shuffle(Numbers.begin(),Numbers.end());  
 
// location of first element of Numbers  
  
    start = Numbers.begin() ;   
 
 // one past the location last element of Numbers    
    end = Numbers.end() ;       
    cout << "Before calling nth_element/n" << endl ;  
  // print content of Numbers  
  
    cout << "Numbers { " ;  
  
    for(it = start; it != end; it++)  
  
        cout << *it << " " ;  
  
    cout << " }/n" << endl ;  
  
    nth_element(start, start+8, end) ;  
 
    cout << "After calling nth_element/n" << endl ;  
  
    cout << "Numbers { " ;  
  
    for(it = start; it != end; it++)  
  
        cout << *it << " " ;  
  
    cout << " }/n" << endl ;  
  
    system("pause");  
  
}  

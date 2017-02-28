#include<iostream>
#include<list>
#include<cmath>
#include<algorithm>
using namespace std;
class data
{
    public:
        int k;
        int d[5];
        double dist;
    double distance(data tdata)
    {
        double r=0;
        for(int j=0;j<k;j++)
            r += (this->d[j]-tdata.d[j])*(this->d[j]-tdata.d[j]);
        r = sqrt(r);
        return r;
    }
};
 
struct node{
 bool operator()(const data& t1,const data& t2){
  return t1.dist<t2.dist;    //会产生升序排序,若改为>,则变为降序
 }
};
 
int test(int n,int k)
{
   int  t,m;
    //cin>>n>>k;
 
    list<data> mydata,mynewdata;
 
    for(int i = 0 ;i < n; i++)
    {
        data tdata;
        tdata.k = k;
        for(int j=0;j<k;j++)
        {
            cin>>tdata.d[j];
        //    cout<<tdata.d[j];
        }
       // cout<<endl;
        mydata.push_back(tdata);
    }
    cin>>t;
    for(int i = 0 ;i < t; i++)
    {
        data tdata;
        for(int j=0;j<k;j++)
        {
            cin>>tdata.d[j];
          //  cout<<tdata.d[j];
        }
       // cout<<endl;
        cin>>m;
        list<data >:: iterator itcon = mydata.begin();
        for(itcon;itcon!=mydata.end();itcon++)
 
        {
            (*itcon).dist = (*itcon).distance(tdata);
        }
        itcon = mydata.begin();
        //std::cout<<"******************";
 
       mydata.sort(node());
        std::cout<<"the closest "<<m<<" points are:"<<tdata.d[0]<<","<<tdata.d[1]<<","<<tdata.d[2]<<endl;
        itcon = mydata.begin();
               for(int i = 0;itcon!=mydata.end() && i<m;itcon++)
       
        {
            for(int j  = 0 ; j < k;j++)
                std::cout<<(*itcon).d[j]<<" ";
            std::cout<<endl;
                     i++;
        }
 
       // std::cout<<"******************";
       // cout << "Hello world!" << endl;
    }
       return 0;
}
int main()
{
    int n,k;
  while(cin>>n>>k)
    test(n,k);
   // cout << "Hello world!" << endl;
    return 0;
}
 
 

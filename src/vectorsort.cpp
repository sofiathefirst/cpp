#include <iostream>
#include <vector>
#include <cmath>
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

bool Comp(const data &a,const data &b)
{
    return a.dist<b.dist;
}

int test(int n,int k)
{
   int  t,m;
    //cin>>n>>k;

    vector<data> mydata,mynewdata;

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
        vector<data >:: iterator itcon = mydata.begin();
        for(itcon;itcon!=mydata.end();itcon++)

        {
            (*itcon).dist = (*itcon).distance(tdata);
        }
        itcon = mydata.begin();
        //std::cout<<"******************";
        for(itcon;itcon!=mydata.end();itcon++)
        {
           // std::cout<<(*itcon).dist<<endl;
        }
        sort(mydata.begin(),mydata.end(),Comp);
        std::cout<<"the closest "<<m<<" points are:"<<endl;
        //itcon = mydata.begin();
        for(int i = 0 ; i < m;i++)
        {
            for(int j = 0 ; j < k;j++)
                std::cout<<mydata[i].d[j]<<" ";
            std::cout<<endl;
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

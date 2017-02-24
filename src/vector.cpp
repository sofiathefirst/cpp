#include<vector>
#include<iostream>
using namespace std;

struct point{int x;int z;};

vector<point> datas;
int ind=0;
void addd(point p)
{
	if(datas.size()<50)
		datas.push_back(p);
	else
		datas[ind++]=p;
	if(ind==50) ind=0;

}
int main()
{
	for(int i=0;i<160;i++)
	{
		struct point p;
		p.x =i;p.z=100;
		addd(p);
	}

	std::cout<<datas.size()<<endl;

	for(int i=0 ; i<datas.size();i++)
		std::cout<<datas[i].x<<",";
	std::cout<<endl<<datas[ind].x;
}

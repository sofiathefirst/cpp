#include<vector>
#include<iostream>
using namespace std;

struct point{int x;int z;};

vector<point> datas;
int oldest_ind=0,newest_ind=0;
int window=50;
void addd(point p)
{
	if(datas.size()<window)
		datas.push_back(p);
	else
		{newest_ind = oldest_ind;datas[oldest_ind++]=p;}

	newest_ind=oldest_ind-1;
	if(oldest_ind==window) {newest_ind=window-1;oldest_ind=0;}

}
int main()
{
	for(int i=0;i<101;i++)
	{
		struct point p;
		p.x =i;p.z=100;
		addd(p);
	}

	std::cout<<datas.size()<<endl;

	for(int i=0 ; i<datas.size();i++)
		std::cout<<datas[i].x<<",";
	std::cout<<endl<<datas[oldest_ind].x<<endl;//ind the oldest one , (ind-1) the newest one
	std::cout<<endl<<datas[newest_ind].x<<endl;
}

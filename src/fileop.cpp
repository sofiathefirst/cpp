#include <stdio.h>
#include<iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
std::string hallparamfile="myparam.txt";

void  get(string str,string name,int &n)
{
	const char *p=str.c_str();
	n=atoi(p+name.size()+1);
	std::cout<<name<<"=:"<<n<<endl;
}
void writef()
{

	ofstream fout(hallparamfile.c_str());
	fout<<"n1: "<<11<<endl;
	fout<<"n2: "<<222<<endl;
	fout<<"n3: "<<3333<<endl;
	fout<<"n4: "<<4444444<<endl;
	fout<<"offset: "<<5555555<<endl;
	fout<<"state: "<<3<<endl;

	fout.close();	
}

void readf()
{
	ifstream _file(hallparamfile.c_str());
	if(!_file)
	{
		cout<<hallparamfile<<"没有被创建";
	}
	else
	{
		//cout<<hallparamfile<<"已经存在";
		int i=0;
		string str;
		int n1,n2,n3,n4,offset,state;
		while(getline(_file,str))
		{
			switch(i)
			{
				case 0:get(str,"n1",n1);i++;break;
				case 1:get(str,"n2",n2);i++;break;
				case 2:get(str,"n3",n3);i++;break;
				case 3:get(str,"n4",n4);i++;break;
				case 4:get(str,"offset",offset);i++;break;
				case 5:get(str,"state",state);i++;break;			
			}				
		}
		_file.close();
	}
}
int main(){
	writef();
	readf();
	
    return 0;

}

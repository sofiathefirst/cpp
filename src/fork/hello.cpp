#include <iostream>
#include <fstream>
 using namespace std;
int main(int argc , char *argv[])
{
    ofstream fout("a34.txt");
    cout<<"aaaaaaaa@@@@@@@@@@@@\n";
    std::cout<<"0"<<argv[0]<<","<<argv[1]<<","<<argv[3]<<","<<argc<<endl;
    fout<<argv[0]<<","<<argv[1]<<","<<argv[2]<<","<<argc<<endl;
    fout.close();
    //exit(0x123478);
return 255;
/*0-255 is ok*/
}

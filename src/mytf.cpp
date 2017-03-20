#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2/LinearMath/Vector3.h>
const double pi = 3.1415926;
#include <stdio.h>
void seeV3(tf2::Vector3 v)
{
	//v.normalize();
	printf("tf2::Vector3 :X=%f,%f,%f",v.getX(),v.getY(),v.getZ());
}
int main()
{

    const tf2::Quaternion midq(tf2::Vector3(0,0,1),pi/5);//x,y,z,w
    const tf2::Matrix3x3 m(midq);
     tf2::Vector3 vb(0,1,0);
     seeV3(m*vb);

}
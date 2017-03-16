#include <iostream>
#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <cmath>

using namespace std;

namespace simcontrol
{	
	enum isacc{Acceleration, Deceleration,Constant_motion,Stop} ;//加速、减速、匀速、停止
	isacc vel_state=Acceleration;
	ros::Time startt;
	ros::Publisher twistpub;
    double diff,v,l,r,w;
	double	k=1;
	double	t1=3;
	double	t2=6;
	double	t3=9;
	double T=2*t1;
	double pi=3.1415926;
	double v_max=0;
	geometry_msgs::Twist myt;
	void twistpubfun()    
	{
		//ROS_WARN("TIMER CALL");
		if(vel_state==Acceleration)
		{
			double t=(ros::Time::now()-startt).toSec();
			double v;
			if(t<t1)
			v=k*0.5*t1/pi*sin(2*pi/T*(t+t1))+k*0.5*t;
			else if (fabs(t-t1)<0.008 || t>t1)
			{
				t=t1;
				v=k*0.5*t1/pi*sin(2*pi/T*(t+t1))+k*0.5*t;
				vel_state=Constant_motion;v_max=v;
			}
			else {vel_state=Constant_motion;v=v_max;}
			ROS_INFO("ACC,V%f,W%f",v,w);
			
			myt.linear.x = v;
			twistpub.publish(myt);
		}
		else if(vel_state==Constant_motion)
		{
			double t=(ros::Time::now()-startt).toSec();
			if (fabs(t-t2)<0.008 || t >t2) vel_state=Deceleration;
			diff=sin((2*pi)/T*(t-t1));
			w=-diff;
			myt.angular.z = w;
			myt.linear.x = v_max;
			ROS_WARN("const,V%f,W%f",v_max,w);
			twistpub.publish(myt);
		}
		else if(vel_state==Deceleration)
		{
			double t=(ros::Time::now()-startt).toSec();
			double v=v_max-0.5*k*(t-t2)+k*0.5*t1/pi*sin((2*pi)/T*(t+t1-t2));
			
			if(t>t3){ v=0;vel_state=Stop;} 
			myt.angular.z =0;
			ROS_INFO("Deceleration,V%f,W%f",v,w);
			myt.linear.x = v;
			myt.angular.z =0;
			twistpub.publish(myt);
		}
		else if(vel_state==Stop )
		{

			myt.linear.x = 0;
			myt.angular.z =0;
			twistpub.publish(myt);
			ros::shutdown();
		}
	} 
}

using namespace simcontrol;


int main( int argc, char** argv )
{

	ros::init(argc, argv, "simcontrol");
	ros::NodeHandle n("~");

    twistpub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
   
	startt=ros::Time::now();
	ros::Timer timer = n.createTimer(ros::Duration(0.01), boost::bind(twistpubfun),false);
  
	ros::spin();

	return 0;
}

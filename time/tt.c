#include <vector>
#include <string>
#include <iostream>
#include "boost/thread/condition_variable.hpp"  
//#include <boost/bind.hpp>
//#include <boost/thread/mutex.hpp>
//#include <boost/foreach.hpp>
#include <boost/thread.hpp>
#include <boost/thread/thread.hpp>
//#include <boost/function.hpp>
//#include <boost/thread/recursive_mutex.hpp>
//#include <boost/thread/mutex.hpp>
//#include <boost/function.hpp>
//#include <boost/thread/recursive_mutex.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/shared_ptr.hpp>
//#include <boost/thread.hpp>
//#include <boost/tokenizer.hpp>
//#include <boost/foreach.hpp>
//#include <boost/algorithm/string.hpp>
//#include <boost/algorithm/string.hpp>

using namespace std; 
class myboost
{
public:
    boost::mutex planner_mutex_;
    boost::condition_variable planner_cond_;
    //we have a goal so start the planner
    boost::thread* planner_thread_;
   //set up the planner's thread
    myboost()
    {
        planner_thread_ = new boost::thread(boost::bind(&myboost::planThread, this));
        spin();
    }
    ~myboost()
    {
        //planner_thread_->interrupt();
       // planner_thread_->join();
       // delete planner_thread_;
    }
    void spin()
    {

    int ii=0;
        while(true)
        {

            std::cin>> ii;
            if (ii==3)
            {
                boost::unique_lock<boost::mutex> lock(planner_mutex_);

                planner_cond_.notify_one();
                lock.unlock();

            }
        }
    }
    void planThread(){

 std::cout<<63<<std::endl;
        bool wait_for_wake = false;
        boost::unique_lock<boost::mutex> lock(planner_mutex_);
        while(true){
             std::cout<<67<<std::endl;
        //check if we should run the planner (the mutex is locked)
       
            planner_cond_.wait(lock);
            std::cout<<72<<std::endl;
       
        }
     
    }


 

};
int main()
{

    myboost myb;
}

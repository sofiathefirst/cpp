#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>
#include <unistd.h>

 class myhellclass
 {
     std::mutex mutex;
     int tickets;

    void mythreada()
    {
        //std::cout<<"1a"<<std::endl;
        while(true)
        {       
           
        sleep(0.5);
        mutex.lock();
            if(tickets>0)
            {
                
                std::cout<<tickets<<" a****  sell out "<<std::endl;
                tickets--;
                mutex.unlock();
               
            }
            else {
            mutex.unlock();
            break;
            }
        }
    }
    void mythreadb()
    {  
        while(true)
        {       
            
        sleep(0.5);
         mutex.lock();
            if(tickets>0)
            {
                
                std::cout<<tickets<<" b####  sell out "<<std::endl;
                tickets--;
                mutex.unlock();
               
            }
            else {
                mutex.unlock();
            break;
            }
        }     
    }
public:
        myhellclass()
     {
        tickets=100;
       mutex.unlock();
     }
    virtual void init();

      ~myhellclass()
     {
         //mutex.unlock();
     }
 };
 void myhellclass::init()
 {
        std::thread ta(&myhellclass::mythreada,this);
        std::thread tb(&myhellclass::mythreadb,this);
        ta.detach();
        tb.join();

        std::cout<<"in mian thread"<<std::endl; 
 }
 int main() 
{
    myhellclass my;
    my.init();
}
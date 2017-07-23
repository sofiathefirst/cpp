#include <stdio.h> /* Standard input/output definitions */
#include <string.h> /* String function definitions */
#include <unistd.h> /* UNIX standard function definitions */
#include <fcntl.h> /* File control definitions */
#include <errno.h> /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include <unistd.h>

#include <stdint.h>
#include <stdbool.h>

/*
 * @brief Open serial port with the given device name
 *
 * @return The file descriptor on success or -1 on error.
 */
struct motor{
uint16_t can_id;
char *device;
int device_fd;
uint8_t mod;
uint8_t send_data[16];
};

void motor_init(struct motor *mymotor, uint16_t can_id);

void enable(struct motor *mymotor);
void disable(struct motor *mymotor);

void send_command(struct motor *mymotor, uint8_t func , int32_t data, uint8_t length, uint8_t wait);

void set_speed(struct motor *mymotor, int temp_speed );
/*
  设置工作模式
    # 0 - 速度闭环模式, 1 - 位置闭环模式, 2 - 电流闭环(力矩模式)， 3 - 放大器;
    # forced - 1强制发送设置指令(程序初始化时使用)，0当设置变化时才发送指令
*/
void set_mod(struct motor *mymotor, uint16_t mode, bool forced );

void save_params(struct motor *mymotor);

void disable(struct motor *mymotor)
{
	send_command(mymotor,0x81, 0, 4, 1);
}
void motor_init(struct motor *mymotor, uint16_t can_id)
{
	memset(mymotor->send_data,0,16);
	mymotor->send_data[0] = 0xAA;
	mymotor->send_data[3] = 8; //can message length
	mymotor->send_data[7] = can_id;
	mymotor->can_id = can_id;
	mymotor->mod = 0;
	
	enable(mymotor);
}
void set_speed(struct motor *mymotor, int temp_speed )
{
        set_mod(mymotor,0,0); //   # 如果不在速度模式下则先设置成速度模式再发速度指令
        send_command(mymotor,0x90, temp_speed,4,0);
        send_command(mymotor,0x91, 0, 0,0);
}
void enable(struct motor *mymotor)
{
	send_command(mymotor, 0x80, 0 , 4,1);
	set_mod(mymotor,0, 1);
}

void send_command(struct motor *mymotor, uint8_t func, int32_t data, uint8_t length,uint8_t wait )
{
	mymotor->send_data[8]=4+length;
	mymotor->send_data[9]= mymotor->can_id;
	mymotor->send_data[10]=func;
	memcpy(mymotor-> send_data+12,&data,4);
	//mymotor->send_data[12]=data;
	for ( int i = 0 ; i<16;i++)
		printf("%x,",mymotor->send_data[i]);
	printf("------\n");
	write(mymotor->device_fd,mymotor->send_data,16);
	if (wait>0)
		sleep(1);
		
}

void set_pwm(struct motor *mymotor, int pwm )   // # 设置P波占空比，sint16，====开环模式，即放大器模式，数字指令，set_mod(0x0300)====
{
   
    pwm = (pwm > 100) ? 100:pwm;
    pwm = (pwm < -100) ? -100:pwm;
    
    set_mod(mymotor,0x0300,0);
    send_command(mymotor,0x95, pwm,4,0);
    send_command(mymotor,0x91, 0, 0,0) ; 
} 

void set_mod(struct motor *mymotor, uint16_t mode , bool forced )
{
	if (mode == mymotor->mod && 0 == forced)
		return ;
	mymotor->mod = mode;

    if (0 == mode)
        send_command(mymotor,0x2a, 0, 4,0);//, 1)
        //print('speed mode')
    else if (1 == mode)
        send_command(mymotor,0x2a, 0x0100, 4,0);//, 1)
        //print('position mode')
    else if( 2 == mode)
        send_command(mymotor,0x2a, 0x0200, 4,0);
    else if (3 == mode)
        send_command(mymotor,0x2a, 0x0300, 4,0);
    else
        send_command(mymotor,0x2a, mode, 4,0);
	
	save_params(mymotor);
	
}

void save_params(struct motor *mymotor)
{
	send_command(mymotor, 0x82,0, 4, 1);
}


int open_port(char *port_device)
{
    int fd; /* File descriptor for the port */

    fd = open(port_device, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1)
    {
        perror("open_port: Unable to open /dev/ttyUSB0 - ");
    }
    else
        fcntl(fd, F_SETFL, 0);

    return (fd);
}

char get_ttyUSB_id(const char* physical_id)
{
  char cmd[256] = "ls -l /sys/class/tty/ | grep ";
  strcat(cmd, physical_id);
  FILE *fp = popen(cmd, "r");
  char buf[256];
  fgets(buf, sizeof(buf), fp); 
  pclose(fp);
  //printf("port_id:%s,   %s\n", physical_id, buf);

  char  *ind = strstr(buf, "ttyUSB");
  if(ind)
  {
    //std::cout<<*(ind+6)<<endl;
    return *(ind+6);
  }
  return '0';
}

int main()
{
    struct termios options;

  char usbid=get_ttyUSB_id("3-1:1.0");

  char myport[]="/dev/ttyUSB0";
  myport[11]=usbid;

    int fd=open_port(myport);
    if(fd==-1){
        return -1;
    }

    tcgetattr(fd, &options);


    //Set the baud rates to 38400...
    cfsetispeed(&options, B115200);
    cfsetospeed(&options, B115200);


    //Enable the receiver and set local mode...
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~CSIZE; /* Mask the character size bits */
    options.c_cflag |= CS8; /* Select 8 data bits */

    //No parity
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;


    //Set the new options for the port...
    tcsetattr(fd, TCSANOW, &options);
	
	struct motor sway_m;
	sway_m.can_id = 23;
	sway_m.device_fd= fd;
	motor_init(&sway_m,sway_m.can_id);
	set_pwm(&sway_m,30);
	sleep(1);
	set_pwm(&sway_m,-30);
	sleep(1);
	set_pwm(&sway_m,0);
	sleep(1);


	set_speed(&sway_m,300);
	sleep(1);
	set_speed(&sway_m,-300);
	sleep(1);
	set_speed(&sway_m,0);
	sleep(1);

	disable(&sway_m);

    close(fd);
}

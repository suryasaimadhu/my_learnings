/*
   Requirements
   Open the controlling terminal:
   /dev/tty

   with read/write permission.

   Use ioctl() with TIOCGWINSZ to obtain:
   Terminal rows
   Terminal columns
Display:
Terminal size: 40 rows x 120 columns
Use write() to display this prompt:
Enter your name:
Use read() on the terminal descriptor to receive the name.
Use write() to display:
Hello, Sai Madhu
Close the terminal descriptor.
Expected execution
Terminal size: 40 rows x 120 columns
Enter your name: Sai Madhu
Hello, Sai Madhu
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<string.h>
int main()
{
	int tty_fd;
	int ret;
	struct winsize window;
	char name[50];
	char output[100];
	tty_fd=open("/dev/tty",O_RDWR);
	if(tty_fd<0)
		printf("tty failed\n");
	ioctl(tty_fd,TIOCGWINSZ,&window);
	printf("Terminal size: %u rows x %u columns\n",window.ws_row,window.ws_col);
	write(tty_fd,"Enter your Name \n",18);
	read(tty_fd,output,sizeof(output)-1);
	write(tty_fd,output,sizeof(output)-1);
	close(tty_fd);
	return 0;
}




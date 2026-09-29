/*
   1) Open the file as read-only:
   open(path, O_RDONLY);
   2)Find its size using:
   file_size = lseek(fd, 0, SEEK_END);

   You already know lseek(), so we can avoid stat() for this first exercise.

   3)Map the complete file:
   mapped_address = mmap(NULL,
   file_size,
   PROT_READ,
   MAP_PRIVATE,
   fd,
   0);
   4)Check for failure:
   if (mapped_address == MAP_FAILED)
   5)Display the mapped data:
   write(STDOUT_FILENO, mapped_address, file_size);
   6)Unmap the region:
   munmap(mapped_address, file_size);
   7)Close the descriptor. */

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/mman.h>
int main()
{
	int fd;
	int file_size;
	char *mapped_address;
	fd=open("mmap.txt",O_RDWR,0666);
	file_size=lseek(fd,0,SEEK_END);
	printf("File size was %d\n",file_size);
	mapped_address=mmap(NULL,file_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(mapped_address==MAP_FAILED)
	{
		perror("mmap");
		close(fd);
	}
	printf("mapped virtual address was %p\n",(void *)mapped_address);
	write(1,mapped_address,file_size);
	mapped_address[2]='x';
	write(1,mapped_address,file_size);
	msync(mapped_address,file_size,MS_SYNC);
	munmap(mapped_address,file_size);
	close(fd);

	return 0;
}

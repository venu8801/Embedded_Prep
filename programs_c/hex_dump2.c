/* write a program to make hex dump */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
int main(int argc, char *argv[])
{
	if(argc < 1)
		printf("Not enough arguements\n");

	int fd;

	fd = open(argv[1], O_RDONLY);
	if(fd < 0)
	{
		printf("failed to open the file\n");
		return -1;

	}

	char buf[10];
	while( (ret = read(fd, buf,10)) < 0)
	{
		
		
	}		
	


	printf("size: %ld bytes read\n",size);
	int k = 0;
	while(k != size)
	{
		printf("%x\t",buf[k]);
		k++;
	}
	printf("\n");

	return 0;
}

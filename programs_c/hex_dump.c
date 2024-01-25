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

	off_t size;
	//finding file size 
	size = lseek(fd, 0, SEEK_END);

	if(size < 0)
		printf("size is invalid\n");
	int *buf = malloc(size * sizeof(int));
	if(buf == NULL)
	{
		printf("failed to allocate memory in heap\n");
		exit(1);
	
	}
	
	lseek(fd, 0, SEEK_SET);

	//read
	size = read(fd, buf, size );

	printf("size: %ld bytes read\n",size);
	int k = 0;
	write(1, buf, 1);
	printf("\n");
	char temp;
	while(k != size)
	{
		temp = buf[k];
		printf("%x\t",temp);
		k++;
	}
	printf("\n");

	return 0;
}

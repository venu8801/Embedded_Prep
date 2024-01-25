#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
int main()
{
	pid_t pid;
	int x = 10;
	pid = fork();


	if(pid < 0)
	{
		return -1;
	}

	if(pid == 0)
	{
		printf("--------------child------------\n");
		printf("%d value of x\n",x);
		printf("%p\n",&x);
		x = 12;
		printf("%d value of x\n",x);
		printf("%p\n",&x);

		sleep(5);
		printf("in child process\n");
		printf("--------------child------------\n");
	}
	else if(pid > 0)
	{
		printf("-----------parent------\n");
		printf("%d value of x\n",x);
		printf("%p\n",&x);
		x = 10;
		printf("%p\n",&x);
		printf("%d value of x\n",x);
		sleep(10);
		printf("parent process\n");
		printf("%ld pid \n",pid);
		printf("-----------parent------\n");
	}

}

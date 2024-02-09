/* implementing a basic shell using fork and exec family of system calls */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
void help(){
	printf("Not enough arguements\n");
	return;

}

int seperate_commands(char *str, char **ptr){

	if(str == NULL || ptr == NULL)
		return -1;
	int i,k;
	ptr[0] = str;
	for(i = 0, k = 1; str[i]; i++){
		if(str[i] == ' '){
			str[i] = 0; //adding null at every space
			if(str[i+1] != '\0')
				ptr[k++] = &str[i+1];
		}
		//printf("%s\n",ptr[i]);

	}
	ptr[k] = NULL;

	for(i = 0; ptr[i] != NULL; i++){
		printf("%s\n",ptr[i]);
	}
	return 0;

}

int main(int argc, char *argv[])
{
	char str[100];
	char *ptr[30] = {0};
	int stat = 0; //status from child
		pid_t pid,cpid;
	printf("------------------------------\n");
	while(1)
	{

		printf("##shell## : ");
		__fpurge(stdin);
		scanf("%[^\n]",str);
		if(strcmp("exit",str) == 0)
			exit(0);
		seperate_commands(str, ptr);

		cpid = fork();
		if(cpid < 0){
			printf("Unable to create a child process exiting\n");
			exit(-1);
		}
		else if(cpid > 0) //parent process
		{
			printf("pid: %d\n",getpid());
			cpid = wait(&stat); //wait for child to terminate
			printf("child process terminated\n");
		}
		else //child process
		{
			printf("pid: %d\n",getpid());
			printf("starting process %s\n",ptr[0]);
			sleep(3);
			execvp(ptr[0], ptr);


		}
	}

}

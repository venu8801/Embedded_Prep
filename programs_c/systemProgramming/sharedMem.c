/* shared memory is an ipc concept used in linux */


#include <stdio.h>
#include <unistd.h>


int main()
{
	key_t shmKey = ftok("./sharedMem.c",'a');

	char *ptr;

	int shmid,ret;

	shmid = shmget(shmKey, 128, IPC_CREAT|0664);
	if(shmid < 0){
		printf("failed to get shared memory\n");
		return -1;
	}
	ptr = shmat(shmid, NULL, 0);

	while(ptr[0] = '\0');
	sleep(1);
	printf("%s\n",ptr);
	ret = shmdt(ptr);


}

#include<stdio.h>
#include<stdlib.h>
int main()
{

	int *ptr;

	ptr = malloc(0);
	
	if(*ptr == NULL)
	{
		printf("ptr is null\n");
	}
	printf("ptr: %p\n",ptr);

	return 0;
}

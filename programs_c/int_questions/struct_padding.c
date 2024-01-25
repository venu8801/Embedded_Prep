#include<stdio.h>
//#pragma pack(1)
struct eg
{
	int x;
	int y;
	char z;
//	int arr[5];
	char a;

};
int main()
{

	struct eg var = {0x12345678,45,'M', 'F'};

	char *ptr;

	int i = 0;
	/*for(i; i < 5; i++)	
	{
		printf("%d ",var.arr[i]);

	}*/
	ptr = (char *)&var;
	int j;
	printf("size of struct: %lu\n",sizeof(struct eg));
	printf("-----Data-----------------Addr-----\n");
	for(i = 0; i < sizeof(struct eg); i++, ptr++)
	{
		printf("0x%x %c %d	%p\t",*ptr,*ptr,*ptr, ptr);
		for(j = 8; j >= 0; j--)
		{
			if(*ptr & (0x1 << j) )
				printf("1");
			else
				printf("0");

		}
		printf("\n");




	}




	return 0;
}

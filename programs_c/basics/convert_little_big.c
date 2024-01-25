/* convert little endian to big endian */
#include <stdio.h>
int main()
{
	unsigned int val = 0x12345678;

	char *ptr = (char *)&val;
	char temp;
	char *end = (ptr + 3);
	printf("end: %p\n",end);

	int i;

	printf("i  addr: %p\n",&i);
	for(i=0; i < 4; i++)
	{
		printf("\n%p   --->   %x\n",ptr++, *ptr);


	}
	ptr = (char *) &val;
	
	for(i = 0; i < 2; i++)
	{
		printf("-->%p\t%d\n",ptr,i);
		temp = *ptr;
		printf("temp : %x\n",temp);
		*ptr = *end;
		*end = temp;
		ptr++;
		end--;

	}
	
	printf("\n------------\n");

	ptr = (char *) &val;
	for(i=0; i < 4; i++)
	{
		printf("\n%p   --->   %x\n",ptr++, *ptr);


	}
	return 0;
}

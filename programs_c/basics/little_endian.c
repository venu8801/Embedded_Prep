/* little endian 
 * the LSB is stored in LSA in little endian system x86 is a little endian */
#include <stdio.h>
int main()
{
	unsigned int val = 0x12345678;
	unsigned char ch = val;
	// LSB 78 and MSB is 12
	
	printf("\nval : %x\n",val);
	int i;
	for(i =31; i >= 0; i--)
	{
		if(val & (0x1 << i))
			printf("1");
		else
			printf("0");
	}

	
	char *ptr =  ((char *)&val);
	for(i=0; i < 4; i++)
	{
		printf("\n%p   --->   %x\n",ptr, *ptr++);


	}
	printf("\nch : %x\n",ch);
	for(i =7; i >= 0; i--)
	{
		if(ch & (0x1 << i))
			printf("1");
		else
			printf("0");
	}
	return 0;
}

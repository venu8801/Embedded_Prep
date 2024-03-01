/* littlval : 12345678 addr: 0x7ffed5b26e78
00010010001101000101011001111000
0x7ffed5b26e78   --->   78

0x7ffed5b26e79   --->   56

0x7ffed5b26e7a   --->   34

0x7ffed5b26e7b   --->   12

ch : 78
e endian 
 * the LSB is stored in LSA in little endian system x86 is a little endian */
#include <stdio.h>
int main()
{
	unsigned int val = 0x12345678;
	unsigned char ch = val;
	// LSB 78 and MSB is 12
	

	/* little endian output
	 *
	 *
	 *
	 *
	 * val : 12345678 addr: 0x7ffed5b26e78
	00010010001101000101011001111000
	0x7ffed5b26e78   --->   78

	0x7ffed5b26e79   --->   56

	0x7ffed5b26e7a   --->   34

	0x7ffed5b26e7b   --->   12

	ch : 78
	*/

	printf("\nval : %x addr: %p\n",val,&val);
	int i;
	for(i =31; i >= 0; i--)
	{
		if(  !((i+1) % 4) ) 
			printf("\t");
		if(val & (0x1 << i))
			printf("1");
		else
			printf("0");
	}

	
	char *ptr =  ((char *)&val);
	for(i=0; i < 4; i++)
	{
		printf("\n%p   --->   %x\n",ptr++,*ptr);


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

/* signed var range exceeding for simplicity taking short int or char */

#include <stdio.h>
int main()
{

	printf("sizeof shortint: %ld\n",sizeof(short int));
	short int val = 0xffff;  // exceeding range as MSB is becoming one stored as it is in the memory 
				  // but while retreiving it does 2s complement and as MSB is 1 represents it as -ve 
	int i;
	printf("val : %d\n",val);
	for(i =31; i >= 0; i--)
	{
		if(val & (0x1 << i))
			printf("1");
		else
			printf("0");
	}

	
	printf("\n");
	/* one more case where range exceeds and -ve number */
	val = -0xffff;
	printf("val : %d\n",val);

	for(i =31; i >= 0; i--)
	{
		if(val & (0x1 << i))
			printf("1");
		else
			printf("0");
	}
	return 0;
}

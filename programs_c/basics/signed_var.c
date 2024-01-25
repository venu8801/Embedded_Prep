/* how a signed var is represented inside memory */
#include <stdio.h>
int main()
{

	int val = -55;  // signed -ve integer 2s complement of 55 is stored inside memory 
			// but while retreiving it does opposite of 2s complement to print same value again
	
	int val2 = 16; // signed +ve integer stored as it is inside memory 
	int i;
	printf("val: %d\n",val);
	for(i =31; i >= 0; i--)
	{
		if(val & (0x1 << i))
			printf("1");
		else
			printf("0");
	}
	printf("\n");
	printf("val2: %d\n",val2);
	for(i =31; i >= 0; i--)
	{
		if(val2 & (0x1 << i))
			printf("1");
		else
			printf("0");
	}
	return 0;

}

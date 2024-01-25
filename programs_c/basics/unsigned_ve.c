/* unsigned in range ---  -ve and +ve values */

#include <stdio.h>
int main()
{	
	unsigned int val = 0xf;  //unsigned in range +ve value
	/* stored as direct binary and while retreiving also direct binary is retreived */

	int i;

	printf("val : %d\n",val);

	for(i = 31; i >= 0; i--)
	{
		if(val & (0x1 << i))
			printf("1");
		else
			printf("0");
	}

	val = -0xf;
     	// unsigned in range -ve value
	
	printf("\nval : %d\n",val);

	for(i =31; i >= 0; i--)
	{
		if(val & (0x1 << i))
			printf("1");
		else
			printf("0");
	}

	return 0;
}

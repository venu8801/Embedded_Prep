/* signed range exceeding with char */
#include <stdio.h>
int main()
{
	signed char val = 0xff;   //signed range exceeding 
				  //stores as its but while retreiving does 2s comp sign is decided by MSB
			//-ve sign will be applied 
	printf("val: %d\n",val);

	int i;
	for(i = 7; i >= 0; i--)
	{
		if(val & (0x1 << i))
			printf("1");
		else
			printf("0");
	}

	 val = -0xff;
	printf("\n");
	printf("val: %d\n",val);

	for(i = 7; i >= 0; i--)
	{
		if(val & (0x1 << i))
			printf("1");
		else
			printf("0");
	}



}
